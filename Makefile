all:MatrixOps   run

MatrixOps: main.o matrixLib.o
	gcc main.o matrixLib.o -o MatrixOps
main.o:main.c
	gcc -c main.c
matrixLib.o: matrixLib.c matrixLib.h
	gcc -c matrixLib.c
clean:
	del *.o MatrixOps.exe
run:
	MatrixOps.exe 400