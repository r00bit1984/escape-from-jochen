CC=gcc
TARGET=game
OBJS=main.o kapitel0.o kapitel1.o kapitel2.o inventory.o
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)
	
main.o: main.c kapitel0.c kapitel0.h kapitel1.c kapitel1.h kapitel2.c kapitel2.h inventory.c inventory.h
	$(CC) -c main.c -o main.o
	
kapitel0.o: kapitel0.c kapitel0.h
	$(CC) -c kapitel0.c -o kapitel0.o
	
kapitel1.o: kapitel1.c kapitel1.h inventory.c inventory.h
	$(CC) -c kapitel1.c -o kapitel1.o

kapitel2.o: kapitel2.c kapitel2.h inventory.c inventory.h
	$(CC) -c kapitel2.c -o kapitel2.o

clean: 
	rm $(OBJS) $(TARGET)
