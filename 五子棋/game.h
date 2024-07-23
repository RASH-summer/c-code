#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>

#define COL 5
#define ROW 5

#define WHITE -1//白子
#define BLACK 1//黑子
#define BLANK 0//空白

#define rule 5 //游戏胜利规则

//打印棋盘
void draw_board(int board[ROW][COL], int row, int col);

//初始化棋盘
void init_board(int board[ROW][COL], int row, int col);

//玩家下棋
void player_chess(int board[ROW][COL], int row, int col);

//电脑落子
void computer_move(int board[ROW][COL], int row, int col);

//判断输赢
int is_win(int board[ROW][COL], int row, int col);