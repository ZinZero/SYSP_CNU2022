all : diary

diary : memo.o calendar.o main.o
	gcc -W -Wall -o diary memo.o calendar.o main.o

memo.o : memo.c
	gcc -W -Wall -c -o memo.o memo.c

calendar.o : calendar.c
	gcc -W -Wall -c -o calendar.o calendar.c

main.o : main.c
	gcc -W -Wall -c -o main.o main.c
