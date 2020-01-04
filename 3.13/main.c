/*
 3.13. A labyrinth is coded using a m x n matrix. The passages are represented by elements equal to 1 placed on
 successive positions on a row or on a column. The requirement is to display all the traces that lead to the exit
 of the labyrinth, starting from an initial position ( i, j ). It is forbidden to pass more than once through the same point.
 */

#include <stdio.h>
#define MAX_LINE 30
#define MAX_COLUMN 30
void printSolution(int m,int n, int path[MAX_LINE][MAX_COLUMN]);
int isPossible(int i,int j, int m, int n, int labyrinth[MAX_LINE][MAX_COLUMN], int path[MAX_LINE][MAX_COLUMN]);
int exitFound(int i,int j, int m, int n);
void findPath(int i,int j, int m, int n, int labyrinth[MAX_LINE][MAX_COLUMN], int path[MAX_LINE][MAX_COLUMN], int p);
int main() {
    int labyrinth[MAX_LINE][MAX_COLUMN], path[MAX_LINE][MAX_COLUMN];
    int m,n,i,j;
    printf ("Please input m and n - dimensions of the labyrinth \n");
    scanf( "%d %d", &m, &n);
    printf("Initialize the paths: \n");
    for(i = 0; i < m; i++)
        for(j= 0; j < n; j++)
        {
            printf("labyrinth[%d][%d]=",i,j);
            scanf("%d", &labyrinth[i][j]);
        }
    for(i = 0; i < m; i++)
        for(j= 0; j < n; j++)
        {
            path[i][j]=0;
        }
    printf("Please input i and j - initial coordinates: ");
    scanf("%d %d",&i,&j);
    findPath(i, j, m, n, labyrinth, path, 1);
    return 0;
}
void printSolution(int m,int n, int path[MAX_LINE][MAX_COLUMN])
{
    for(int i = 0; i < m; i++)
    { for(int j = 0; j < n; j++)
        {
            printf("%d ",path[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int isPossible(int i,int j, int m, int n, int labyrinth[MAX_LINE][MAX_COLUMN], int path[MAX_LINE][MAX_COLUMN]) {
    return (i >= 0 && j >= 0 && i <= m - 1 && j <= n - 1 && labyrinth[i][j] == 1 && path[i][j] == 0);

}

int exitFound(int i,int j, int m, int n){
   return  (i == m-1 || j == n-1 || i == 0 || j == 0);

}

void findPath(int i,int j, int m, int n, int labyrinth[MAX_LINE][MAX_COLUMN], int path[MAX_LINE][MAX_COLUMN], int p)
{
    int k;
    int xMove[4]={0,-1,0,1},yMove[4]={1,0,-1,0};
    path[i][j]=p;
    if(exitFound(i, j, m, n))
        printSolution(m, n, path);
    else
    {
        for(k = 0;k<4;k++)
        {
            if(isPossible(i+xMove[k],j+yMove[k],m,n,labyrinth ,path))
                findPath(i+xMove[k],j+yMove[k],m,n, labyrinth, path, p+1);
        }
    }
    path[i][j]=0;

}