#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>

#define COL 5
#define ROW 5

#define WHITE -1//����
#define BLACK 1//����
#define BLANK 0//�հ�

#define rule 5 //��Ϸʤ������

//��ӡ����
void draw_board(int board[ROW][COL], int row, int col);

//��ʼ������
void init_board(int board[ROW][COL], int row, int col);

//�������
void player_chess(int board[ROW][COL], int row, int col);

//��������
void computer_move(int board[ROW][COL], int row, int col);

//�ж���Ӯ
int is_win(int board[ROW][COL], int row, int col);