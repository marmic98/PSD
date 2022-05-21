main.exe: main.o item.o BST.o btree.o list.o
	gcc main.o item.o BST.o btree.o list.o -o main.exe 
	
item.o: item.c
	gcc -c item.c
	
BST.o: BST.c 
	gcc -c BST.c

btree.o: btree.c
	gcc -c btree.c

list.o: list.c
	gcc -c list.c
	
main.o: main.c item.o BST.o btree.o list.o
	gcc -c main.c item.o BST.o btree.o list.o
	 
clean:
	del .f *o *.exe