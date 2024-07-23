#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"


void menu()
{
	printf("-------------------------\n");
	printf("------ 1.play -----------\n");
	printf("------ 0.exit -----------\n");
	printf("-------------------------\n");

}

void game()
{
	//游戏棋盘
	int board[ROW][COL];
	
	//初始化棋盘
	init_board(board, ROW,COL);


	//打印游戏棋盘
	draw_board(board, ROW, COL);

	int ret = 0;
	while (1)
	{
		//玩家下棋
		player_chess(board, ROW, COL);

		//判断输赢
		ret = is_win(board, ROW, COL);

		if (ret != BLANK)
		{
			//游戏结束
			break;
		}
		
		/*	判断输赢
			1.玩家赢了  返回玩家的棋子
			2.人机赢了  返回人机的棋子
			3.平局      返回8
			4.游戏继续  返回 BLANK
		*/

		

		//电脑落子
		computer_move(board, ROW, COL);
		//判断输赢
		ret = is_win(board, ROW, COL);

		if (ret != BLANK)
		{
			//游戏结束
			break;
		}
	}

	if (ret == BLACK)
	{
		printf("玩家赢了\n");
		draw_board(board, ROW, COL);


	}
	else if (ret == WHITE)
	{
		printf("人机赢了\n");
		draw_board(board, ROW, COL);

	}
	else if (ret == 8)
	{
		printf("平局\n");
		draw_board(board, ROW, COL);

	}
}



int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	
	do 
	{
		menu();
		printf("选择菜单：");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				//开始游戏
				game();
				break;
			case 0:
				//退出游戏
				printf("退出游戏\n");
				break;
			default:
				printf("选择错误，重新选择\n");
				break;
		}
	} while (input);



	return 0;
}