g++11:=g++ -std=c++11 -stdlib=libc++ -MMD -MP
cflags:=-lncurses

TARGET:=matrix.out
CPPFILES:=$(wildcard *.cpp)
#OBJFILES:=$(CPPFILES:.cpp=.o)
OBJFILES:=$(addprefix obj/,$(notdir $(CPPFILES:.cpp=.o)))
OBJDIRECTORY:=obj


.PHONY: all
all: $(OBJDIRECTORY) $(TARGET)

$(OBJDIRECTORY):
	mkdir -p $(OBJDIRECTORY)

$(TARGET): $(OBJFILES)
	$(g++11) $(cflags) -o $@ $^ -g

$(OBJDIRECTORY)/%.o: %.cpp
#%.o: %.cpp
	$(g++11) -c -o $@ $< -g

-include $(addprefix obj/,$(notdir $(CPPFILES:.cpp=.d)))


.PHONY: clean
clean:
	rm -f $(OBJFILES) $(TARGET)
	rm -rf $(OBJDIRECTORY)
