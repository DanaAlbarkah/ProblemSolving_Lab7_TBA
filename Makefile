# Makefile to compile and run task1.c, task2.c, task3.c, task4.c, and task5.c

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# Executables
EXE1 = task1
EXE2 = task2
EXE3 = task3
EXE4 = task4
EXE5 = task5

# Source files
SRC1 = task1.c
SRC2 = task2.c
SRC3 = task3.c
SRC4 = task4.c
SRC5 = task5.c

# Default target
all: $(EXE1) $(EXE2) $(EXE3) $(EXE4) $(EXE5)

# Compile each task
$(EXE1): $(SRC1)
	$(CC) $(CFLAGS) -o $@ $<

$(EXE2): $(SRC2)
	$(CC) $(CFLAGS) -o $@ $<

$(EXE3): $(SRC3)
	$(CC) $(CFLAGS) -o $@ $<

$(EXE4): $(SRC4)
	$(CC) $(CFLAGS) -o $@ $<

$(EXE5): $(SRC5)
	$(CC) $(CFLAGS) -o $@ $<

# Run all executables
run: all
	./$(EXE1)
	./$(EXE2)
	./$(EXE3)
	./$(EXE4)
	./$(EXE5)

# Clean up generated files
clean:
	rm -f $(EXE1) $(EXE2) $(EXE3) $(EXE4) $(EXE5)

