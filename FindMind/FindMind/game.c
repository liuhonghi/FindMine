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
    int count = EASY_COUNT;
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


static int get_mine_count(char mine[ROWS][COLS],int x,int y)
{
    return mine[x-1][y-1]+
           mine[x-1][y]+
            mine[x-1][y+1]+
            mine[x][y-1]+
            mine[x][y+1]+
            mine[x+1][y-1]+
            mine[x+1][y]+
            mine[x+1][y+1]-8*'0';
}




void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col)
{
    int x = 0;
    int y = 0;
    int win = 0;
    while(win<row*col-EASY_COUNT)
    {
        printf("请输入排查坐标:\n");
        scanf("%d%d",&x,&y);
        if(x>=1 && x<=row && y>=1 && y<=col)
        {
            if(mine[x][y] == '1')
            {
                printf("不好意思，你被炸死了!\n");
                DisplayBoard(mine, row, col);
                break;
            }
            else
            {
                int count = get_mine_count(mine,x,y);
                show[x][y] = count + '0';
                DisplayBoard(show, row, col);
                win++;
            }
        }
        else
        {
            printf("坐标非法\n");
        }
    }
    if( win == row*col-EASY_COUNT )
    {
        printf("恭喜你胜利\n");
        DisplayBoard(mine, row, col);
    }
}
