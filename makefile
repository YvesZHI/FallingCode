g++1x:=g++ -std=c++14 -stdlib=libc++ -MMD -MP
cflags:=-lncurses

TARGET:=matrix.out
CPPFILES:=$(wildcard *.cpp)
OBJDIRECTORY:=.obj
#OBJFILES:=$(CPPFILES:.cpp=.o)
OBJFILES:=$(addprefix $(OBJDIRECTORY)/,$(notdir $(CPPFILES:.cpp=.o)))


.PHONY: all
all: $(OBJDIRECTORY) $(TARGET)

$(OBJDIRECTORY):
	mkdir -p $(OBJDIRECTORY)

$(TARGET): $(OBJFILES)
	$(g++1x) $(cflags) -o $@ $^ -g

$(OBJDIRECTORY)/%.o: %.cpp
#%.o: %.cpp
	$(g++1x) -c -o $@ $< -g

-include $(addprefix $(OBJDIRECTORY)/,$(notdir $(CPPFILES:.cpp=.d)))


.PHONY: clean
clean:
	rm -f $(OBJFILES) $(TARGET)
	rm -rf $(OBJDIRECTORY)
