#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>


void menu()
{
	//���ܲ˵�
	printf("***********************************\n");
	printf("********* 1.add  2.sub  ***********\n");
	printf("********* 3.mul  4.div  ***********\n");
	printf("********* 0.exit        ***********\n");
}

int Add(int x, int y)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;
}

int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}

int main5()
{
	//����ָ��-ת�Ʊ�-������
	int(*pfarr[])(int, int) = { 0, Add, Sub, Mul, Div };//�ú���ָ�������������0������ռλ��
	int input = 0;
	int a = 0;
	int b = 0;
	int ret = 0;
	do {
		menu();
		printf("��ѡ��:");
		scanf("%d", &input);
		if (input >= 1 && input <= 4)
		{
			printf("������2����������");
			scanf("%d %d", &a, &b);
			ret = pfarr[input](a,b);//����input��ֵ�����ö�Ӧ�ĺ���
			printf("%d\n", ret);
		}
		else if (input == 0)
		{
			printf("�˳�!\n");
			break;
		}
		else
		{
			printf("ѡ���������ѡ��\n");
		}

		
	} while (input);
	return 0;

	/*
		�ú���ָ������������ղŵĴ��룬���Ҫ�������Ĺ���ֻ��Ҫ�ı�˵���������µĺ����ͺ��ˣ�����Ҫд�ظ��Ĵ��룬�����������˺ܶ�
		��Ȼ�����ǲ�֧��С���ļ����
	*/
}

int main4()
{
	//ʵ��һ������汾�ļ�����
	int input = 0;
	int a = 0;
	int b = 0;
	int ret = 0;
	do {
		menu();
		printf("��ѡ��:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("������2����������");
			scanf("%d %d", &a, &b);
			ret = Add(a, b);
			printf("%d\n", ret);
			break;
		case 2:
			printf("������2����������");
			scanf("%d %d", &a, &b);
			ret = Sub(a, b);
			printf("%d\n", ret);
			break;
		case 3:
			printf("������2����������");
			scanf("%d %d", &a, &b);
			ret = Mul(a, b);
			printf("%d\n", ret);
			break;
		case 4:
			printf("������2����������");
			scanf("%d %d", &a, &b);
			ret = Div(a, b);
			printf("%d\n", ret);
			break;
		case 0:
				break;
		default:
			printf("ѡ����󣬴�������\n");
		}
	} while (input);
	return 0;

	/*
		����һ���򵥼�������ʵ�֣�����Ժ���Ҫ�������������ܵĻ�switch�������ģ�
		������úܳ��ܳ����������5�������Ǿͻ�һֱ��case9 
	*/
}



/*
int Add(int x, int y)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;
}
*/

//����ָ������ 
int main3()
{
	//����ָ�� - �����飬�����д�ŵĶ��Ǻ���ָ��

	int (*p1)(int, int) = Add;
	int (*p2)(int, int) = Sub;

	//��Ҫ��pq��p2������һ����������

	int (*parr[4])(int, int) = { Add,Sub };//parr��һ������ָ������

	return 0;
}




typedef int(*parr_t)[5];
int main2()
{
	int arr[5];
	int (*p)[5] = &arr;
	
	parr_t p2 = &arr;


	return 0;
}


// typedef ���԰Ѹ������ͼ򵥻�
typedef int* ptr_t;
typedef void(*pf_t)(int);//pf_t ��������

int main1()
{
	int* p;
	ptr_t ptr;
	
	pf_t p1;
	//void(*p3)(int); //����ָ��

	pf_t signal(int, pf_t);

	
	return 0;
}