CC = g++
# location of Header files
INCDIRS = . ./include/ ./test/generateTestCases ./test/generateAnswers ./test/generateResults
OPT = -O0
# Generate files that encode make rules for the .h dependencies
DEPFLAGS = -MM -MP 
CFLAGS = -std=c++17 -Wall -Wextra -g $(foreach D,$(INCDIRS),-I$(D)) $(OPT)


SRC = src
OBJ = obj
BIN = bin
TEST = test
DEP = dependencies

# Get all Source cpp files
SRC_FILES = $(wildcard $(SRC)/*.cpp)
# Create the object file names with prefix obj
SRC_OBJS = $(patsubst %.cpp, $(OBJ)/%.o, $(SRC_FILES))


# Gets all Test cpp files from subdirectories
TEST_FILES = $(wildcard $(TEST)/*.cpp $(TEST)/*/*.cpp)
# Remove main
TEST_FILES := $(filter-out $(TEST)/main.cpp, $(TEST_FILES))
# Create the object files and add prefix obj
TEST_OBJS = $(patsubst %.cpp, $(OBJ)/%.o, $(TEST_FILES)) $(SRC_OBJS)


DEPFILES = $(patsubst %.cpp, $(DEP)/%.d, $(TEST_FILES) $(SRC_FILES))
# $(patsubst %.cpp, %.d, $(SRC_FILES))


TEST_TARGET = $(BIN)/test
LIN_TRANS = $(BIN)/linearTransformation


# Rules
all: $(TEST_TARGET) $(LIN_TRANS)

$(TEST_TARGET): $(TEST_OBJS)
	$(CC) -o $@ $(TEST)/main.cpp $^

$(LIN_TRANS): $(SRC_OBJS)
	$(CC) -o $@ examples/linearTransformation.cpp $^

$(OBJ)/%.o: %.cpp
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o  $@ $^
	mkdir -p $(DEP)/$(subst $(OBJ)/,,$(@D))
	$(CC) $(CFLAGS) $(DEPFLAGS) -MT $@ $*.cpp > $(patsubst $(OBJ)/%.o, $(DEP)/%.d, $@)


# @ so it does not print to the std out
clean:
	@rm -rf $(BIN)/* $(OBJ)/* $(DEP)/*

# include the dependencies
-include $(DEPFILES)

# add .PHONY so that the non-targetfile - rules work even if a file with the same name exists.
.PHONY: all clean