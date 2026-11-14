CC = gcc
# CXX = g++
SRC_DIR = src
INC_DIR = include
OBJDIR = obj

CFLAGS = -Wall -Wextra -Wpedantic -I$(INC_DIR)
# CPPFLAGS = -std=c++17
LDFLAGS =

C_SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/list.c $(SRC_DIR)/utils.c $(SRC_DIR)/addr.c
C_OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJDIR)/%.o,$(C_SRCS))

TARGETS = cLab
#cppLab

all: $(TARGETS)

$(OBJDIR):
	mkdir -p $@

$(OBJDIR)/%.o: $(SRC_DIR)/%.c | $(OBJDIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

cLab: $(C_OBJS)
	$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)

# cppLab: $(SRC_DIR)/main.cpp
# 	$(CXX) $(SRC_DIR)/main.cpp $(CPPFLAGS) $(FLAGS) -o cppLab

clean:
	rm -rf $(OBJDIR) $(TARGETS)

.PHONY: all clean
