CXX = g++
SRC_DIR = src
INC_DIR = include
OBJDIR = obj
DEBUG_FLAG = -D DEBUG

FLAGS = -Wall -Wextra -Wpedantic -I$(INC_DIR)
CPPFLAGS = -std=c++23
LDFLAGS =

TARGETS = cLab cppLab

all:
	$(CXX) $(SRC_DIR)/main.cpp $(SRC_DIR)/list.cpp $(CPPFLAGS) $(FLAGS) -o cppLab

DEBUG:
	$(CXX) $(DEBUG_FLAG) $(SRC_DIR)/main.cpp $(SRC_DIR)/list.cpp $(CPPFLAGS) $(FLAGS) -o cppLab

clean:
	rm -f $(TARGETS)

.PHONY: all clean
