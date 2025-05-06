# Compiler and flags
CC=gcc
CFLAGS=-I/usr/include
LDFLAGS=-L/usr/lib -lcs50

# Default target (runs when you type "make")
all: f_meow

# Compile 02-answer.c
02-answer: 02-answer.c
	$(CC) $(CFLAGS) 02-answer.c $(LDFLAGS) -o 02-answer

# Compile compare
compare: compare.c
	$(CC) $(CFLAGS) compare.c $(LDFLAGS) -o compare

# Compile f_meow.c
f_meow: f_meow.c
	$(CC) $(CFLAGS) f_meow.c $(LDFLAGS) -o meow

# Compile mario.c
mario: mario.c
	$(CC) $(CFLAGS) mario.c $(LDFLAGS) -o mario

# Compile calculator.c
calculator: calculator.c
	$(CC) $(CFLAGS) calculator.c $(LDFLAGS) -o calculator

# Clean target to delete the compiled binary
clean:
	rm -f 02-answer
