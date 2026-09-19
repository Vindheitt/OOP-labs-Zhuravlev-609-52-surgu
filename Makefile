CC = gcc
CXX = g++
SRC_DIR = src
INC_DIR = include
OBJDIR = obj

FLAGS = -Wall -Wextra -Wpedantic -I$(INC_DIR)
CPPFLAGS = -std=c++17
LDFLAGS =

TARGETS = cLab cppLab

all: $(TARGETS)

cLab: $(SRC_DIR)/main.c
	$(CC) $(SRC_DIR)/main.c $(SRC_DIR)/list.c $(FLAGS) -o cLab

cppLab: $(SRC_DIR)/main.cpp
	$(CXX) $(SRC_DIR)/main.cpp $(CPPFLAGS) $(FLAGS) -o cppLab

clean:
	rm -f $(TARGETS)

.PHONY: all clean
