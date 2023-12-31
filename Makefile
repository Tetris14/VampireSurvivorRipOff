# Project settings
EXEC := VampireSurvivorRipoff
SRC_DIR := src
INC_DIR := includes
OBJ_DIR := obj

# Compiler settings
CXX := g++
CXXFLAGS := -std=c++17 -Wall -I$(INC_DIR) -I/opt/homebrew/Cellar/sfml/2.6.1/include
LDFLAGS := -L/opt/homebrew/Cellar/sfml/2.6.1/lib

# SFML Libraries
SFML_LIBS := -lsfml-graphics -lsfml-window -lsfml-system

# Find all source files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Main target
$(EXEC): $(OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@ $(SFML_LIBS)

# Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create the object file directory
$(OBJ_DIR):
	mkdir -p $@

# Clean target
clean:
	rm -rf $(OBJ_DIR) $(EXEC)

re:
	make clean
	make
	make run

# Run target
run: $(EXEC)
	./$(EXEC) 1920 1080

# Phony targets
.PHONY: clean run
