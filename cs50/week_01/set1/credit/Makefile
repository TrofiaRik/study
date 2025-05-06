# Compiler and flags
CC=gcc
CFLAGS=-I/usr/include
LDFLAGS=-L/usr/lib -lcs50
# Default target (runs when you type "make")
all: credit

# Compile credit.c
credit: credit.c
	$(CC) $(CFLAGS) credit.c $(LDFLAGS) -o credit
