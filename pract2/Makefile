.PHONY: clean # Чтобы цель clean работала даже если у нас где-то есть файл с именем clean

all: main
program: libstatic.a
	gcc src/main.c -I ./include -L. -lstatic -o program
main: main.o samolet.o
	gcc -o main main.o samolet.o
libstatic.a: samolet.o
	ar rcs libstatic.a samolet.o
main.o: src/main.c
	gcc -c src/main.c -o main.o -I ./include

samolet.o: src/samolet.c
	gcc -c src/samolet.c -o samolet.o -I ./include



clean:
	rm -rf *.o *.a main program

run: all
	./main