CC= g++
CFLAGS= -g -w -Wall

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^

main: main.o AVLTree.o node.o queue.o queueNode.o
	$(CC) -o $@ $^
	del /f *.o

test: test.o AVLTree.o node.o queue.o queueNode.o
	$(CC) $(CFLAGS) -o $@ $^
	del /f *.o
clean:
	del /f *.o *exe