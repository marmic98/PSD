test.exe: list.o test.o 
	gcc list.o test.o -o test.exe

list.o: list.c
	gcc -c list.c

test.o: test.c
	gcc -c test.c

clean: 
	del *.o *.exe