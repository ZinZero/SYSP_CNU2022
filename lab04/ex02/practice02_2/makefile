all : diary.out

diary.out : add.o sub.o mul.o div.o memo.o calendar.o main.o
	gcc -o diary.out add.o sub.o mul.o div.o memo.o calendar.o main.o

mian.o : main.c
	gcc -c main.c

add.o : add.c
	gcc -c add.c

sub.o : sub.c
	gcc -c sub.c

mul.o : mul.c
	gcc -c mul.c

div.o : div.c
	gcc -c div.c

memo.o : memo.c
	gcc -c memo.c

calendar.o : calendar.c
	gcc -c calendar.c

clean :
	rm -rf *.o
	rm -rf *.out