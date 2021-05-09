CC= g++
CFLAGS= -g -w -Wall

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^

main: main.o HashMapTable.o HashMapEntry.o
	$(CC) -o $@ $^
	del /f *.o

test: test.o HashMapTable.o HashMapEntry.o
	$(CC) $(CFLAGS) -o $@ $^
	del /f *.o
	
clean:
	del /f *.o *exe