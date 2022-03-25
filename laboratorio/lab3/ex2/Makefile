maxDist.exe: maxDist.o punto.o utility.o
	gcc maxDist.o punto.o utility.o -o maxDist.exe -lm

maxDist.o: maxDist.c
	gcc -c maxDist.c

punto.o: punto.c
	gcc -c punto.c

utility.o: utility.c
	gcc -c utility.c

clean: 
	rm *.o
