biblioteca.exe: biblioteca.o libro.o utility.o
	gcc biblioteca.o libro.o utility.o -o biblioteca.exe

biblioteca.o: biblioteca.c
	gcc -c biblioteca.c

libro.o: libro.c
	gcc -c libro.c

utility.o: utility.c
	gcc -c utility.c

clean: 
	del *.o *.exe