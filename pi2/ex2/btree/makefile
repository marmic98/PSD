main.exe: main.o item.o btree.o
	gcc main.o item.o btree.o -o main.exe 
	
item.o: item.c
	gcc -c item.c
	
btree.o: btree.c 
	gcc -c btree.c
	
main.o: main.c item.o btree.o
	gcc -c main.c item.o btree.o 
	 
clean:
	del .f *o *.exe