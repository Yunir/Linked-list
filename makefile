FLAGS=-ggdb -c -o

all: main

main: main.o list.o file.o
	gcc -ggdb -o main main.o list.o file.o

main.o: main.c
	gcc $(FLAGS) main.o main.c

list.o: list.c
	gcc $(FLAGS) list.o list.c

file.o: file.c
	gcc $(FLAGS) file.o file.c

clean:
	rm -f main.o list.o file.o main linkedList
