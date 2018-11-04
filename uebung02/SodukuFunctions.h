#define N 9

/*
    Functions to provide a solution for a Soduku
    Implementation in <sodukulib.so>
*/
void print_sudoku( int sudoku[N][N]);
int solve_sodoku(int i, int j, int sudoku[N][N]);
int is_valid(int z, int i, int j, int sudoku[N][N]);
int dumb_sodoku(int sudoku[N][N]);
int is_end(int sudoku[N][N]);