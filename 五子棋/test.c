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
	//��Ϸ����
	int board[ROW][COL];
	
	//��ʼ������
	init_board(board, ROW,COL);


	//��ӡ��Ϸ����
	draw_board(board, ROW, COL);

	int ret = 0;
	while (1)
	{
		//�������
		player_chess(board, ROW, COL);

		//�ж���Ӯ
		ret = is_win(board, ROW, COL);

		if (ret != BLANK)
		{
			//��Ϸ����
			break;
		}
		
		/*	�ж���Ӯ
			1.���Ӯ��  ������ҵ�����
			2.�˻�Ӯ��  �����˻�������
			3.ƽ��      ����8
			4.��Ϸ����  ���� BLANK
		*/

		

		//��������
		computer_move(board, ROW, COL);
		//�ж���Ӯ
		ret = is_win(board, ROW, COL);

		if (ret != BLANK)
		{
			//��Ϸ����
			break;
		}
	}

	if (ret == BLACK)
	{
		printf("���Ӯ��\n");
		draw_board(board, ROW, COL);


	}
	else if (ret == WHITE)
	{
		printf("�˻�Ӯ��\n");
		draw_board(board, ROW, COL);

	}
	else if (ret == 8)
	{
		printf("ƽ��\n");
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
		printf("ѡ��˵���");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				//��ʼ��Ϸ
				game();
				break;
			case 0:
				//�˳���Ϸ
				printf("�˳���Ϸ\n");
				break;
			default:
				printf("ѡ���������ѡ��\n");
				break;
		}
	} while (input);



	return 0;
}