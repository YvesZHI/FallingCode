g++1x:=g++ -std=c++14 -stdlib=libc++ -MMD -MP
cflags:= -Wall -lncurses

TARGET:=matrix.out
SRS:=$(shell find * -type f -name "*.cpp")
OBJDIR:=.obj
OBJ:=$(addprefix $(OBJDIR)/,$(SRS:.cpp=.o))
BIN:=bin


.PHONY: install
install: $(BIN) $(BIN)/$(TARGET) $(OBJ)

$(BIN):
	@echo "creating bin directory";
	@mkdir -p $(BIN);

$(BIN)/$(TARGET): $(OBJ)
	$(g++1x) $(cflags) $^ -o $@ -g

$(OBJ): $(OBJDIR)/%.o: %.cpp
	@if [ ! -d "$(@D)" ]; then\
		echo "creating obj directories"; \
		mkdir -p "$(@D)";\
	fi
	$(g++1x) -c -o $@ $< -g


-include $(OBJ:.o=.d)


.PHONY: clean
clean:
	@echo "removing bin and obj";
	@rm -rf $(BIN);
	@rm -rf $(OBJDIR);
