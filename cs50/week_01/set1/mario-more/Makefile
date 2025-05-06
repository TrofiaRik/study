# Compiler and flags
CC=gcc
CFLAGS=-I/usr/include
LDFLAGS=-L/usr/lib -lcs50
# Default target (runs when you type "make")
all: mario

# Compile mario.c
mario: mario.c
	$(CC) $(CFLAGS) mario.c $(LDFLAGS) -o mario
# Compile mario2.c
mario2: mario2.c
	$(CC) $(CFLAGS) mario2.c $(LDFLAGS) -o mario2

