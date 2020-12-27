prog: my_strlen.o main.o
	gcc -std=gnu99 -g -o prog my_strlen.o main.o
main.o: main.c
	gcc -std=gnu99 -g -c main.c
my_strlen.o: my_strlen.c
	gcc -std=gnu99 -g -c my_strlen.c
clean:
	rm -rf prog *.o

