# Makefile
CC = gcc
CFLAGS = -Wall -g

TARGET = myprogram.exe
OBJS = main.o sum.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c sum.h
	$(CC) $(CFLAGS) -c main.c

sum.o: sum.c sum.h
	$(CC) $(CFLAGS) -c sum.c

clean:
	rm -f $(TARGET) $(OBJS)
