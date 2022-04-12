main.exe: stack.o main.o itemStr.o
	gcc stack.o main.o itemStr.o -o main.exe -lm

main.o: main.c
	gcc -c main.c

stack.o: stack.c
	gcc -c stack.c

itemStr.o: itemStr.c
	gcc -c itemStr.c

clean: 
	del *.o *.exe