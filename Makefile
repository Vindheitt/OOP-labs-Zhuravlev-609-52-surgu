CC = gcc
C_SRCDIR = srcC
CPP_SRCDIR = srcCPP
OBJDIR = obj

FLAGS = -Wall -Wextra -Wpedantic
CPPFLAGS = -std=c++17 -lstdc++
LDFLAGS =

TARGETS = cLab cppLab

all: $(TARGETS)

cLab: $(C_SRCDIR)/main.c
	$(CC) $(C_SRCDIR)/main.c $(FLAGS) -o cLab

cppLab: $(CPP_SRCDIR)/main.cpp
	$(CC) $(CPP_SRCDIR)/main.cpp $(CPPFLAGS) $(FLAGS) -o cppLab

clean:
	rm -f $(TARGETS)

.PHONY: all clean
