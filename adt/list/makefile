test.exe: list.o test.o punto.o utility.o
	gcc list.o test.o punto.o utility.o -o test.exe -lm

list.o: list.c
	gcc -c list.c

test.o: test.c
	gcc -c test.c

punto.o: punto.c
	gcc -c punto.c

utility.o: utility.c
	gcc -c utility.c

clean: 
	rm *.o *.exe