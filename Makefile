CXX = g++
SRC_DIR = src
INC_DIR = include
OBJDIR = obj
DEBUG_FLAG = -D DEBUG

FLAGS = -Wall -Wextra -Wpedantic -I./$(INC_DIR)
CPPFLAGS = -std=c++23
LDFLAGS =

ALL_SRC_FILES = $(SRC_DIR)/main.cpp $(SRC_DIR)/list.cpp $(SRC_DIR)/utils.cpp

TARGETS = cLab cppLab

all:
	$(CXX) $(ALL_SRC_FILES) $(CPPFLAGS) $(FLAGS) -o cppLab

DEBUG:
	$(CXX) $(DEBUG_FLAG) $(ALL_SRC_FILES) $(CPPFLAGS) $(FLAGS) -o cppLab

clean:
	rm -rf $(TARGETS) $(OBJDIR)

.PHONY: all DEBUG clean
