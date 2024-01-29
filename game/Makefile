CC=gcc
TARGET=compiled
OBJS=main.o kapitel0.o
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)
	
main.o: main.c kapitel0.c kapitel0.h
	$(CC) -c main.c -o main.o
	
kapitel0.o: kapitel0.c kapitel0.h
	$(CC) -c kapitel0.c -o kapitel0.o

clean: 
	trash-put $(OBJS) $(TARGET)