# Compiler and flags
CC=gcc
CFLAGS=-I/usr/include
LDFLAGS=-L/usr/lib -lcs50
# Default target (runs when you type "make")
all: hello

# Compile hello.c
hello: hello.c
	$(CC) $(CFLAGS) hello.c $(LDFLAGS) -o hello

