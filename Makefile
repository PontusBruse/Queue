.DEFAULT_GOAL := all

CC = g++

PROG_EXE = main
BUILD_DIR = build

OBJECTS = $(shell find . -name "*.cpp")
OBJECTS :=$(OBJECTS:./%.cpp=%.o)
OBJECTS := $(addprefix $(BUILD_DIR)/, $(OBJECTS))

define CLEAN
	@echo "Project clean"
	rm -rf $(BUILD_DIR)
endef

all: .mkbuild $(BUILD_DIR)/$(PROG_EXE)
	@echo "==================Targets========================="
	@echo "====> clean: to clean the project"
	@echo "====> run: to build and run the program"
	@echo "=================================================="

$(BUILD_DIR)/$(PROG_EXE): $(OBJECTS)
	@$(CC) $+ -o $@

$(BUILD_DIR)/%.o: %.cpp
	@$(CC) -MMD -c $< -o $@

-include $(OBJECTS:.o=.d)

run: .mkbuild $(BUILD_DIR)/$(PROG_EXE)
	@./$(BUILD_DIR)/$(PROG_EXE)

.mkbuild:
	@mkdir -p $(BUILD_DIR)

clean:
	$(CLEAN)

.PHONY: all .mkbuild clean run
