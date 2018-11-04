#include <stdio.h>
#include <stdlib.h>

#define N 9

/*
    @author: Henrik Gerdes, Manuel Eversmeyer

    Actual functions to print and solve a Sodoku
*/


/*
    Prints the Soduku-grid
*/
void print_sudoku( int sudoku[N][N])
{
    int i,j;

    printf("\n+---------+---------+---------+\n");
    for(i = 0; i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(j%3 ==0)
            {
                printf("|");
            };
            printf("%2d ", sudoku[i][j]);
        }
        if(i%3==2)
        {
            printf("|\n+---------+---------+---------+\n");
        }else{
            printf("|\n");
        }
    }
}

/*
    Checks if a given number z is valid to set on position i,j in
    a Soduku-grid
*/
int is_valid(int z, int i, int j, int sudoku[N][N])
{
    if(z>9 || z<1)
    {
        return 0;
    }

    int k;
    for(k=0; k<N;k++)
    {
        if(sudoku[i][k] == z)
        {
            //printf("Fehler in Zeile gefunden");
            return 0;
        }
        if(sudoku[k][j] == z)
        {
            //printf("Fehler in Spalte gefunden");
            return 0;
        }
    }


    int square_i = i/3;
    int square_j = j/3;
    square_i *=3;
    square_j *=3;

    int limit_i = square_i +3;
    int limit_j = square_j +3;

    int index_i = 0;
    int index_j = 0;

    for(index_i = square_i;index_i < limit_i;index_i++)
    {
        for(index_j = square_j;index_j < limit_j;index_j++)
        {
            if(sudoku[index_i][index_j] == z)
            {
                //printf("Fehler in Feld gefunden");
                return 0;
            }
        }
    }


    return 1;
}

/*
    Checks if there are still free positions in the grid
*/
int is_end(int sudoku[N][N])
{
    int i = 0;
    int j = 0;
    for(i = 0; i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(sudoku[i][j]==0)
            {
                return 1;
            }
        }
    }
    return 0;
}

/*
    Solves a Soduku using backtracking
*/
int solve_sodoku(int i, int j, int sudoku[N][N])
{
    //printf("Solve mit: i=%d   und j=%d\n", i ,j);
    if(j==N)
    {
        i++;
        j=0;
    }

    if(!is_end(sudoku))
    {
        return 1;
    }

    if(sudoku[i][j])
    {
        if(solve_sodoku(i,j+1,sudoku))
        {
            return 1;
        }
        return 0;
    }

    int z = 0;
    for(z=1;z<=N;z++)
    {
        if(is_valid(z,i,j,sudoku))
        {
            sudoku[i][j] = z;
            if(solve_sodoku(i,j+1,sudoku))
            {
                return 1;
            }
            sudoku[i][j] = 0;  
        }
    }

    return 0;
}

/*
    Saves a Soduku-grid to a file
*/
int dumb_sodoku(int sudoku[N][N])
{
    FILE *fp;
    fp = fopen("Soduku_dumb.txt","w");

    if(fp==NULL)
    {
        return 1;
    }
    
    int i = 0;
    int j = 0;
    for(i = 0; i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            fprintf(fp,"%d ", sudoku[i][j]);
        }
        fprintf(fp,"\n");
    }
    fclose(fp);

    return 0;
}