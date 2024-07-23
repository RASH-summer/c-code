#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

//��ʼ������
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
//��������
void draw_chessman(int type, char* set)
{
	if (type == WHITE)
		printf("��");
	else if (type == BLACK)
		printf("��");
	else
		printf("%s ", set);
}




//��ӡ����
/*
��    ��    ��

��    ��    ��

��    ��    ��
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
					draw_chessman(board[i][j], "��");
				else if (j == col-1)
					draw_chessman(board[i][j], "��");
				else
					draw_chessman(board[i][j], "��");
			}
			printf("\n");
		}
		else if (i == row-1)
		{
			int j = 0;
			for (j = 0; j < col; j++)
			{
				if (j == 0)
					draw_chessman(board[i][j], "��");
				else if (j == col-1)
					draw_chessman(board[i][j], "��");
				else
					draw_chessman(board[i][j], "��");
			}
			printf("\n");
		}
		else
		{
			int j = 0;
			for (j = 0; j < col; j++)
			{
				if (j == 0)
					draw_chessman(board[i][j], "��");
				else if (j == col-1)
					draw_chessman(board[i][j], "��");
				else
					draw_chessman(board[i][j],"��");
			}
			printf("\n");
		}
	}
}

//�������
void player_chess(int board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	while (1)
	{
		printf("�������....����������:");
		scanf("%d %d", &x, &y);//����x,y����

		//�ж������Ƿ�Ϸ�
		if ((x >= 1 && x <= col) && (y >=1 && y <= col))
		{
			if (board[x-1][y-1] == BLANK)
			{
				board[x - 1][y - 1] = BLACK;//����
				break;
			}
			else
			{
				printf("�������������ӣ�������������\n");
			}
		}
		else
		{
			printf("�Ƿ����꣬��������\n");
		}
	}

	system("cls");

	//�ٴλ������̲���������ӵ�λ�û��Ƴ���
	draw_board(board, ROW, COL);
}


//��������
void computer_move(int board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	printf("�˻�����...\n");
	Sleep(1000);//����һ��

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

	//��ӡ����
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

//�ж���Ӯ
is_win(int board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		int flag = 1;
		for (j = 0; j < col; j++)
		{
			//�ж���
			if ((board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i][j + 3] + board[i][j + 4] == rule) && (board[i][j] != BLANK))
			{
				//5�����ɷ�����ҵ�����
				return board[i][j];
			}

			//�ж���
			if ((board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 3][j] + board[i + 4][j] == rule) && (board[i][j] != BLANK))
			{
				//5�����ɷ�����ҵ�����
				return board[i][j];
			}

			//�ж����Խ���
			if ((board[i][j] + board[i + 1][j+1] + board[i + 2][j+2] + board[i + 3][j+3] + board[i + 4][j+4] == rule) && (board[i][j] != BLANK))
			{
				//5�����ɷ�����ҵ�����
				return board[i][j];
			}

			//�жϷ��Խ���
			if ((board[i][j] + board[i + 1][j - 1] + board[i + 2][j - 2] + board[i + 3][j - 3] + board[i + 4][j - 4] == rule) && (board[i][j] != BLANK))
			{
				//5�����ɷ�����ҵ�����
				return board[i][j];
			}
			
			//�ж����Ƿ��Ѿ�����
			if (is_full(board, ROW, COL))
			{
				return 8;
			}

		}			
	}
	return BLANK;

}