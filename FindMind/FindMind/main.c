//
//  main.c
//  FindMind
//
//  Created by HiLau on 2023/6/11.
//
#include "game.h"

//扫雷游戏的简单实现
//思路 - 两个二维数组做棋盘 - 一个设置雷 - 一个显示排雷的信息

void game()
{
    char mine[ROWS][COLS] = {0};
    char show[ROWS][COLS] = {0};
  
    InitBoard(mine, ROWS, COLS,'0');
    InitBoard(show, ROWS, COLS,'*');

    DisplayBoard(show, ROW, COL);
    
    SetMine(mine,ROW,COL);
    //DisplayBoard(mine, ROW, COL);
    
    FindMine(mine,show, ROW, COL);
}

void menu()
{
    printf("**************************\n");
    printf("********* 1.play *********\n");
    printf("********* 0.exit *********\n");
    printf("**************************\n");
}

void test()
{
    int input = 0;
    srand((unsigned int) time(NULL));
    do
    {
        menu();
        printf("请选择>:");
        scanf("%d",&input);
        switch(input)
        {
            case 1:
            {
                game();
                break;
            }
            case 0:
            {
                printf("退出游戏\n");
            }
            default:
                printf("选择错误，请重新选择\n");
        }
                
    }
    while(input);
        
}


int main()
{
    test();
    return 0;
}
