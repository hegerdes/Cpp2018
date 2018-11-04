Soduku_solver:	SodukuSolver.o sodukulib.so
	gcc -o Soduku_solver SodukuSolver.o -L. -lsodukulib
	export LD_LIBRARY_PATH=/path/to/library:${LD_LIBRARY_PATH}

sodukulib.so:	SodukuFunctions.o
	 gcc -shared -o libsodukulib.so SodukuFunctions.o

SodukuFunctions.o: SodukuFunctions.c
	gcc -Wall -fPIC -c SodukuFunctions.c

SodukuSolver.o:	SodukuSolver.c SodukuFunctions.h
	gcc -Wall -c SodukuSolver.c

clean: 
	rm *.so
	rm *.o
	rm Soduku_solver