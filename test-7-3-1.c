#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>



//ð������ĺ���˼�룺�������ڵ�Ԫ�ؽ��бȽ�
void sort(int* arr, int len)
{
	//ȷ��ð����������� n-1
	int i = 0;
	for (i = 0; i < len; i++)
	{
		//һ��ð������
		int flag = 1; //���������Ѿ����������
		int j = 0;
		for (j = 0; j < len - i; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				//����
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;//���������
			}
		}
		if (flag == 1)
			break; //˵��������������ѭ��
	}
}
void print_arr(int * arr, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d ", i[arr]);
	}
	printf("\n");
}

int main()
{
	int arr[] = { 10,9,8,7,6,5,4,3,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	
	sort(arr, sz);//��Ϊ����
	print_arr(arr, sz);

	return 0;
}


void print(int* arr)
{
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);//�ò�������Ԫ�صĸ���
	/*
		��Ϊ�β���������Ԫ�صĵ�ַ
		4 / 4 = 1
		���ԣ�Ӧ������������������ܵõ�����Ԫ�صĸ���
	
	*/

	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
int main3()
{
	int arr[] = { 1,2,3,4,5 };
	print(arr);
	return 0;
}

int main2()
{
	int arr[5] = { 0 };

	int sz = sizeof(arr) / sizeof(arr[0]);
	int* ptr = arr;
	int i = 0;
	//����
	for (i = 0; i < sz; i++)
	{
		scanf("%d", ptr + i);
	}
	//���
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *(ptr + i));
	}

	return 0;
}

int main1()
{
	//�����������
	int arr[] = { 1,2,3,4,5 };
	printf("%p\n", arr);
	printf("%p\n", &arr[0]);

	//����������������Ԫ�صĵ�ַ?

	//printf("%zd\n", sizeof(arr));//������˵����������ôӦ����4byte������8��byte
	//���н����20��

	/*
		���䣺
		��������������Ԫ�صĵ�ַ���������������⣺
		1.sizeof(������)���������������ʾ�������飬sizeof(������)���������������Ĵ�С����λ���ֽ�
		2.sizeof(&�����������������������ʾ�������飬&������ȡ��������������ĵ�ַ��
	*/

	printf("%p\n", &arr);//����Ԫ�ص�ַһ����Ϊʲô������
	/*
		����������ͬһ���ڴ�ռ䣬��������Ҳ�Ǵ���Ԫ�ص�ַ��ʼ�ɣ�����������Ԫ�ص�ַ��һ����
		����ʲô����
	*/

	printf("arr        ================= %p\n", arr);
	printf("arr + 1    ================= %p\n", arr + 1);
	printf("arr[0]     ================= %p\n", &arr[0]);
	printf("arr[0] + 1 ================= %p\n", &arr[0] + 1);

	printf("&arr[      ================= %p\n", &arr);
	printf("&arr + 1   ================= %p\n", &arr + 1);
	//ע������ĵ�ַ������1����Ȼ������20���ֽڣ�Ҳ���Ǽ���20���ֽڣ�������16���Ƶ�0x14

	//0000 0000 0000 0000 0000 0000 0001 0100
	//0x 00 00 00 14

	return 0;
}