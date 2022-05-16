main.exe: stack.o main.o item.o
	gcc stack.o main.o item.o -o main.exe -lm

main.o: main.c
	gcc -c main.c

stack.o: stack.c
	gcc -c stack.c

item.o: item.c
	gcc -c item.c

clean: 
	del *.o *.exe