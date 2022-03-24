objects = tutorato2.o matrix.o utility.o
exe = tutorato2.exe
tutorato2.exe: tutorato2.o matrix.o utility.o
	gcc $(objects) -o $(exe)

tutorato2.o: tutorato2.c
	gcc -c tutorato2.c

matrix.o: matrix.c
	gcc -c matrix.c

utility.o: utility.c
	gcc -c utility.c

clean:
	-del $(exe) $(objects)