CC = g++
# location of Header files
INCDIRS = . ./include/ ./test/generateTestCases ./test/generateAnswers ./test/generateResults
OPT = -O0
# Generate files that encode make rules for the .h dependencies
CFLAGS = -std=c++17 -Wall -Wextra -g $(foreach D,$(INCDIRS),-I$(D)) $(OPT)


SRC = src
OBJ = obj
BIN = bin
TEST = test

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
CLIENT_TARGET = $(BIN)/client


# Rules
all: $(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJS)
	$(CC) -o $@ $(TEST)/main.cpp $^

$(LIN_TRANS): $(SRC_OBJS)
	$(CC) -o $@ examples/linearTransformation.cpp $^

$(CLIENT_TARGET): $(SRC_OBJS)
	$(CC) -o $@ client.cpp $^

$(OBJ)/%.o: %.cpp
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o  $@ $^


# @ so it does not print to the std out
clean:
	@rm -rf $(BIN)/* $(OBJ)/*

# add .PHONY so that the non-targetfile - rules work even if a file with the same name exists.
.PHONY: all clean