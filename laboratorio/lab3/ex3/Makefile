riordina.exe: riordina.o punto.o utility.o
	gcc riordina.o punto.o utility.o -o riordina.exe -lm

punto.o: punto.c
	gcc -c punto.c

utility.o: utility.c
	gcc -c utility.c

riordina.o: riordina.c
	gcc -c riordina.c

clean:
	rm *.o