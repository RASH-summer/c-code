#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

//初始化棋盘
void init_board(int board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			board[i][j] = BLANK;
		}
	}
}
//绘制棋子
void draw_chessman(int type, char* set)
{
	if (type == WHITE)
		printf("○");
	else if (type == BLACK)
		printf("●");
	else
		printf("%s ", set);
}




//打印棋盘
/*
┌    ┬    ┐

├    ┼    ┤

└    ┴    ┘
*/
void draw_board(int board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (i == 0)
		{
			int j = 0;
			for (j = 0; j < col; j++)
			{
				if (j == 0)
					draw_chessman(board[i][j], "┌");
				else if (j == col-1)
					draw_chessman(board[i][j], "┐");
				else
					draw_chessman(board[i][j], "┬");
			}
			printf("\n");
		}
		else if (i == row-1)
		{
			int j = 0;
			for (j = 0; j < col; j++)
			{
				if (j == 0)
					draw_chessman(board[i][j], "└");
				else if (j == col-1)
					draw_chessman(board[i][j], "┘");
				else
					draw_chessman(board[i][j], "┴");
			}
			printf("\n");
		}
		else
		{
			int j = 0;
			for (j = 0; j < col; j++)
			{
				if (j == 0)
					draw_chessman(board[i][j], "├");
				else if (j == col-1)
					draw_chessman(board[i][j], "┤");
				else
					draw_chessman(board[i][j],"┼");
			}
			printf("\n");
		}
	}
}

//玩家落子
void player_chess(int board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	while (1)
	{
		printf("玩家落子....请输入坐标:");
		scanf("%d %d", &x, &y);//输入x,y坐标

		//判断坐标是否合法
		if ((x >= 1 && x <= col) && (y >=1 && y <= col))
		{
			if (board[x-1][y-1] == BLANK)
			{
				board[x - 1][y - 1] = BLACK;//黑子
				break;
			}
			else
			{
				printf("该坐标已有棋子，重新输入坐标\n");
			}
		}
		else
		{
			printf("非法坐标，重新输入\n");
		}
	}

	system("cls");

	//再次绘制棋盘并将玩家落子的位置绘制出来
	draw_board(board, ROW, COL);
}


//电脑落子
void computer_move(int board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	printf("人机落子...\n");
	Sleep(1000);//休眠一秒

	while (1)
	{
		x = rand() % row;
		y = rand() % col;

		if (board[x][y] == BLANK)
		{
			board[x][y] = WHITE;
			break;
		}
	}
	system("cls");

	//打印棋盘
	draw_board(board, ROW, COL);
}


static int is_full(int board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == BLANK)
				return BLANK;
		}
	}
}

//判断输赢
is_win(int board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		int flag = 1;
		for (j = 0; j < col; j++)
		{
			//判断行
			if ((board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i][j + 3] + board[i][j + 4] == rule) && (board[i][j] != BLANK))
			{
				//5子连成返回玩家的棋子
				return board[i][j];
			}

			//判断列
			if ((board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 3][j] + board[i + 4][j] == rule) && (board[i][j] != BLANK))
			{
				//5子连成返回玩家的棋子
				return board[i][j];
			}

			//判断正对角线
			if ((board[i][j] + board[i + 1][j+1] + board[i + 2][j+2] + board[i + 3][j+3] + board[i + 4][j+4] == rule) && (board[i][j] != BLANK))
			{
				//5子连成返回玩家的棋子
				return board[i][j];
			}

			//判断反对角线
			if ((board[i][j] + board[i + 1][j - 1] + board[i + 2][j - 2] + board[i + 3][j - 3] + board[i + 4][j - 4] == rule) && (board[i][j] != BLANK))
			{
				//5子连成返回玩家的棋子
				return board[i][j];
			}
			
			//判断棋是否已经满了
			if (is_full(board, ROW, COL))
			{
				return 8;
			}

		}			
	}
	return BLANK;

}