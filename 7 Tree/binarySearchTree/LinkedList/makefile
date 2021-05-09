CC= g++
CFLAGS= -g -w -c -Wall

%.o: %.cpp
	$(CC) $(CFLAGS) $^

main: main.o binarySearchTree.o node.o queue.o queueNode.o
	$(CC) -o $@ $^

test: test.o binarySearchTree.o node.o queue.o queueNode.o
	$(CC) -o $@ $^
clean:
	del /f *.o *exe