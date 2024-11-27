# Makefile

# Compiler and flags (easy to modify or extend)
CC = gcc
# CFLAGS = -Wall -Wextra -pedantic

# Variable to capture filename passed as argument
TARGET = $(file)

# Default target
.PHONY: all
all:
	@echo "Usage: make build file=filename (without .c extension)"

# Build target: compiles the given file into an executable with the same name
.PHONY: build
build:
	@if [ -z "$(TARGET)" ]; then \
		echo "Error: No filename specified."; \
		echo "Usage: make build file=filename (without .c extension)"; \
	else \
		$(CC) $(CFLAGS) $(TARGET).c -o $(TARGET); \
		echo "Compiled $(TARGET).c to $(TARGET)"; \
	fi

# Clean target: removes any compiled binaries
.PHONY: clean
clean:
	@rm -f *.o
