main.exe: main.o item.o BST.o btree.o
	gcc main.o item.o BST.o btree.o -o main.exe 
	
item.o: item.c
	gcc -c item.c
	
BST.o: BST.c 
	gcc -c BST.c

btree.o: btree.c
	gcc -c btree.c

main.o: main.c item.o BST.o btree.o
	gcc -c main.c item.o BST.o btree.o
	 
clean:
	del .f *o *.exe