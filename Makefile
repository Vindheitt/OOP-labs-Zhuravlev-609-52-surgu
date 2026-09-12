CC = gcc
CXX = g++
C_SRCDIR = srcC
CPP_SRCDIR = srcCPP
OBJDIR = obj

FLAGS = -Wall -Wextra -Wpedantic
CPPFLAGS = -std=c++17
LDFLAGS =

TARGETS = cLab cppLab

all: $(TARGETS)

cLab: $(C_SRCDIR)/main.c
	$(CC) $(C_SRCDIR)/main.c $(FLAGS) -o cLab

cppLab: $(CPP_SRCDIR)/main.cpp
	$(CXX) $(CPP_SRCDIR)/main.cpp $(CPPFLAGS) $(FLAGS) -o cppLab

clean:
	rm -f $(TARGETS)

.PHONY: all clean
