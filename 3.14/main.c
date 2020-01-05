
/*
3.14. A knight is placed in the upper left square on a chess board of size n x n. Display all the possible paths of the knight on
the chess board, such a way that every square is reached only once.
 */
#include <stdio.h>
#define MAX_LENGHT 30
int isSafe(int x, int y, int n, int board[MAX_LENGHT][MAX_LENGHT]);
void printSolution(int n,int board[MAX_LENGHT][MAX_LENGHT]);
void solveKnightProblem(int i,int j, int n, int trace, int board[MAX_LENGHT][MAX_LENGHT], int *existSolution);
int main() {
    int board[MAX_LENGHT][MAX_LENGHT], n,i,j;
    int existSolution=0;
    printf ("Please input the length of the chess board");
    scanf("%d", &n);
    for (i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            board[i][j]=0;
        }
        solveKnightProblem(0,0, n,1,board, &existSolution);
        if (existSolution==0) printf("There are no solutions for n=%d", n);
    return 0;


}

int isSafe(int x, int y, int n, int board[MAX_LENGHT][MAX_LENGHT])
{
    return ( x >= 0 && x<n && y >= 0 && y<n && board[x][y] == 0);
}

void printSolution(int n,int board[MAX_LENGHT][MAX_LENGHT])
{
    for (int i = 0; i<n;i++)
    {
        for (int j= 0; j< n; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}
void solveKnightProblem(int i,int j, int n, int trace, int board[MAX_LENGHT][MAX_LENGHT], int *existSolution)
{
    int k;
    int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
    board[i][j]=trace;
    if (trace == n*n)
    {
        printSolution(n, board);
    *existSolution=1;
    }
    else
    {
        for(k = 0; k < n; k++)
        {
            if( isSafe(i + xMove[k], j + yMove[k], n, board))
                solveKnightProblem(i+xMove[k], j+yMove[k], n, trace+1,board, existSolution);
        }
    }
    board[i][j]=0;
}
