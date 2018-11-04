#include <stdio.h>
#include "SodukuFunctions.h"

/*
    @author: Henrik Gerdes, Manuel Eversmeyer

    Main for a small programm that solves a Soduku using backtracking
    The Sokoku bust be hardcoded.

    Implementation of the actual code is in a shared libary called 
    <sodukulib.so>

    Command to seth path to libsodukulib.so:
    export LD_LIBRARY_PATH=/path/to/library:${LD_LIBRARY_PATH}
*/

int main(int argv, char** argc)
{

    int sudoku[N][N] = {{0,0,0,0,0,8,0,3,0},
						{0,3,0,5,0,0,4,7,1},
						{2,0,0,1,0,0,6,9,0},
                        {5,0,0,0,0,2,1,0,0},
						{1,2,4,0,0,0,9,6,3},
						{0,0,6,4,0,0,0,0,2},
                        {0,8,9,0,0,5,0,0,7},
						{3,5,2,0,0,9,0,4,0},
						{0,1,0,3,0,0,0,0,0}};

    printf("Eingegebenes Sodoku:\n");
    print_sudoku(sudoku);

    if(solve_sodoku(0,0,sudoku))
    {
        printf("\nGeloestes Soduku:\n");
        print_sudoku(sudoku);
    }else
    {
        printf("\nSodoku konnte nicht geloest werden\n");
    }

    return 0;
}