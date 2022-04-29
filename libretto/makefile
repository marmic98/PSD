main.exe: main.o libretto.o list.o item.h
	gcc main.o libretto.o list.o item.h -o main.exe
	
item.o: item.c
	gcc -c item.c

libretto.o: libretto.c list.o

list.o: list.c item.o
	gcc -c list.c item.o
	
main.o: main.c item.o list.o libretto.o 
	gcc -c main.c item.o list.o libretto.o 
	 
clean:
	del .f *o *.exe