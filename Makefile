# Makefile for compiling the Windows utils(win-utils) commands

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall

# Source files
SRC = src/touch/wtouch.c

# Output executable
TARGET = touch

# Default target to compile the program
all: $(TARGET)

# Rule to compile the target
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Clean rule to remove the compiled executable
clean:
	rm -f $(TARGET)

# Phony targets to avoid conflicts with files named 'all' or 'clean'
.PHONY: all clean
