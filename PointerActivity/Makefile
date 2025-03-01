# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Targets
TARGET = test_pointers
OBJS = main.o read_data.o

# Primary target
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile main.c
main.o: main.c read_data.h
	$(CC) $(CFLAGS) -c main.c -o main.o

# Rule to compile read_data.c
read_data.o: read_data.c read_data.h
	$(CC) $(CFLAGS) -c read_data.c -o read_data.o

# Clean target to remove compiled files
clean:
	rm -f $(TARGET) $(OBJS)
