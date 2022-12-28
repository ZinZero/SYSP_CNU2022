all : ex01.out

ex01.out : ex01.o mul.o div.o
	gcc -o ex01.out ex01.o mul.o div.o

ex01.o : ex01.c
	gcc -c ex01.c

mul.o : mul.c
	gcc -c mul.c

div.o : div.c
	gcc -c div.c
