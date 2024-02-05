# Makefile

# Find all C source files in the current directory and subdirectories
SRC := $(wildcard *.c) $(wildcard */*.c)

# Create object file names based on the source files
OBJ := $(SRC:.c=.o)

# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra

# Target executable
TARGET := shaegine

# Build rule
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Generic rule to compile C source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(TARGET)