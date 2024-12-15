# Makefile

# Compiler and flags (easy to modify or extend)
CC = gcc

.PHONY: build
build:
	$(CC) ccwc.c utils.c -o ccwc; \
	echo "Compiled ccwc.c utils.c to ccwc";
