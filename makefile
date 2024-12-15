# Compiler and Flags
CXX = g++
CXXFLAGS = -o3 -std=c++17 -g

# Directories
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

# Source Files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Executable Name
TARGET = $(BUILD_DIR)/main

# Default Target
all: $(TARGET)

# Link the main executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Build object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR) 
