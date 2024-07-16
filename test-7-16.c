#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int com_int(const void* p1, const void* p2)
{
	return *(int*)p1 - *(int*)p2;
}
void print(int* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
#include <stdlib.h>
int main()
{
	/*
		qsort�ǿ⺯����Ҳ���Ǳ���д�����ģ��������ã���ʱ����Ϊ������ԱA
		���ǳ���ԱA��ʵ�����������ʱ�򣬲�����֪��������qsort������ʲô�����͵����ݣ���������Ƴ���void*
	*/

	int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	printf("����ǰ:\n");
	print(arr, sz);
	qsort(arr, sz, sizeof(arr[0]), com_int);
	printf("�����:\n");
	print(arr,sz);

	return 0;
}


int main2()
{
	// qsort �ǿ⺯�����������������������͵����� 
	// �ο����ף�cplusplus.com

	/*
		�ú�������4��������
		void qsort (void* base, size_t num, size_t size,
            int (*compar)(const void* p1,const void* p1));
		
		��1��������void* base
		��2��������size_t num
		��3��������size_t size
		��4��������int (*compar)(const void p1*,const void* p2))

		��1������������ָ����������ʼ��ַ
		��2�������������������Ԫ�ظ���
		��3������������������Ԫ�ص�����Ԫ�صĴ�С����λ���ֽ�
		��4������������compar��һ������ָ�룬ָ��ĺ����ܹ��Ƚ�2��Ԫ��

		��4���������ⲹ�䣺
						p1ָ���Ԫ�� == p2ָ���Ԫ�أ�����0
						p1ָ���Ԫ�� < p2ָ���Ԫ�أ����� <0 ������
						p1ָ���Ԫ�� > p2ָ���Ԫ�أ����� >0 ������
	*/

	//void* Ҳ��һ��ָ������ ��Ϊ��ͨ�õ�ָ�����ͣ���˼���� void*���͵�ָ��������Խ��������������͵ĵ�ַ��ָ������Ͱ��ʲô��ַ�����Էţ�

	//����Ҳ��ȱ�ݣ�����++ �� --�Ȳ���

	//int a = 9;
	//void* p = &a;

	//p++;
	//*p; // ������Ҳ����



	return 0;
}



void menu()
{
	printf("***********************************************\n");
	printf("*********** 1.Add  2.Sub **********************\n");
	printf("*********** 3.Mul  4.Div **********************\n");
	printf("*********** 0.Exit       **********************\n");
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

void calc(int(*pf)(int, int))
{
	int a = 0;
	int b = 0;
	int ret = 0;

	printf("������2����������");
	scanf("%d %d", &a, &b);
	ret = pf(a, b);
	printf("%d\n", ret);

	//ͨ��pfָ��ȥ��������ָ��ĺ����������õĺ�����Ϊ�ص�����
}

int main1()
{
	/*
		�ص���������

		�ص�������һ��ͨ������ָ����õĺ���
		�Ѻ���ָ����Ϊ�������ݸ���һ�������������ָ�뱻������������ָ��ĺ���ʱ�������ú������ǻص�������
		�ص����������ɸú�����ʵ�ַ�ֱ�ӵ��ã��������ض���ʱ�����������ʱ�������һ�����á�

	*/

	int input = 0;
	do {
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			calc(Add);
		case 2:
			calc(Sub);
		case 3:
			calc(Mul);
		case 4:
			calc(Div);
		case 0:
			printf("�˳�\n");
			break;
		default:
			printf("ѡ�������������\n");
			break;
		}

	} while (input);

	return 0;
}