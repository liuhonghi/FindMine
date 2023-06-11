//
//  game.c
//  test
//
//  Created by HiLau on 2023/6/9.
//

//扫雷
#include "game.h"


void InitBoard(char board[ROWS][COLS],int rows,int cols,char set)
{
    int i = 0;
    int j = 0;
    for(i = 0;i<rows;i++)
    {
        for(j = 0;j<cols;j++)
        {
            board[i][j] = set;
        }
    }
}

void DisplayBoard(char board[ROWS][COLS],int row,int col)
{
    int i = 0;
    printf("---------------------扫雷----------------------\n");
    for(i = 0;i<=col;i++)
    {
        printf("%d ",i);
    }
    printf("\n");
    for(i = 1;i<=row;i++)
    {
        printf("%d ",i);
        int j = 0;
        for(j = 1;j<=col;j++)
        {
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
    printf("---------------------扫雷----------------------\n");
}

void SetMine(char mine[ROWS][COLS],int row,int col)
{
    int count = 10;
    while(count)
    {
        int x = rand()%row +1;
        int y = rand()%col +1;
        if(mine[x][y] == '0')
        {
            mine[x][y] = '1';
            count --;
        }
    }
}
