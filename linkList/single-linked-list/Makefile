CC=gcc

CFLAGS=-c -Wall

all: hello


hello:	Util.o LinkedList_Insert.o LinkedList_Delete.o LinkedList_Swap.o LinkedList_Reverse.o LinkedList_Merge.o LinkedList_Count.o RemoveLoop.o Main.o
	$(CC) -o list.out  LinkedList_Count.o LinkedList_Delete.o LinkedList_Merge.o LinkedList_Reverse.o Util.o LinkedList_Insert.o LinkedList_Swap.o RemoveLoop.o  Main.o -I. 
	


Util.o:	Util.c
	$(CC) -c Util.c

LinkedList_Insert.o:	LinkedList_Insert.c
	$(CC) -c  LinkedList_Insert.c


LinkedList_Delete.o:	LinkedList_Delete.c
	$(CC) -c  LinkedList_Delete.c

LinkedList_Swap.o:	LinkedList_Swap.c
	$(CC) -c  LinkedList_Swap.c


LinkedList_Reverse.o:	LinkedList_Reverse.c
	$(CC) -c  LinkedList_Reverse.c


LinkedList_Merge.o:	LinkedList_Merge.c
	$(CC) -c  LinkedList_Merge.c


LinkedList_Count.o:	LinkedList_Count.c
	$(CC) -c  LinkedList_Count.c


RemoveLoop.o:	RemoveLoop.c
	$(CC) -c RemoveLoop.c

Main.o:	Main.c
	$(CC) -c Main.c


clean:
	rm -rf *.o 	


 

 
