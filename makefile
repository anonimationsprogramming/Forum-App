CXX      := g++
CXXFLAGS := -Wall -Wextra -Werror -std=c++17 -MMD -MP

SRC_DIR  := src
OBJ_DIR  := obj
TARGET   := forum-app

# Find all .cpp files recursively
SRCS := $(shell find $(SRC_DIR) -name "*.cpp")

# Convert src path → obj path
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@

# Compile any src/...cpp into obj/...o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

re: clean all
