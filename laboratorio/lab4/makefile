biblioteca.exe: biblioteca.o libro.o
	gcc biblioteca.o libro.o -o biblioteca.exe

biblioteca.o: biblioteca.c
	gcc -c biblioteca.c

libro.o: libro.c
	gcc -c libro.c

clean: 
	rm *.o