FLAGS=-ggdb -c -o

all: main

main: main.o list.o
	gcc -ggdb -o main main.o list.o

main.o: main.c
	gcc $(FLAGS) main.o main.c

list.o: list.c
	gcc $(FLAGS) list.o list.c

clean:
	rm -f main.o list.o main
