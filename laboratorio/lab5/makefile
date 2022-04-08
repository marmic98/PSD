main.exe: list.o main.o punto.o utility.o
	gcc list.o main.o punto.o utility.o -o main.exe -lm

list.o: list.c
	gcc -c list.c

main.o: main.c
	gcc -c main.c

punto.o: punto.c
	gcc -c punto.c

utility.o: utility.c
	gcc -c utility.c

clean: 
	del *.o *.exe