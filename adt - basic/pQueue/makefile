main.exe: PQueue.o main.o
	gcc PQueue.o main.o -o main.exe -lm

main.o: main.c
	gcc -c main.c

PQueue.o: PQueue.c
	gcc -c PQueue.c

clean: 
	del *.o *.exe