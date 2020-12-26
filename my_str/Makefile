prog: my_strlen.o main.o
	g++ -g -o prog my_strlen.o main.o
main.o: main.c
	g++ -g -c main.c
my_strlen.o: my_strlen.c
	g++ -g -c my_strlen.c
clean:
	rm -rf prog *.o

