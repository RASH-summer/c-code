#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <string.h>

int main9()
{
	//Ұָ��
	//���Ұָ�����ָ��ָ���λ���ǲ���֪�ģ�����ġ�����ȷ�ġ�û����ȷ���Ƶģ�


	int* p;//�ֲ���������ʼ�����õ��������ֵ
	//*p = 20;
	

	return 0;
}



int main9()
{
	//ָ��Ĺ�ϵ���㣺ʵ�ʾ���ָ�루��ַ���Ƚϴ�С

	int arr[] = { 1,2,3,4,5 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int* p = arr;

	while (p < arr + sz)
	{
		printf("%d ", *p);
		p++;
	}


	return 0;
}


int my_strlen(char* str)
{
	char* start = str;
	//ָ��ʵ��
	while (*str != '\0')
	{
		str++;
	}
	return str - start;
}

int my_strlen1(char* str)
{
	int count = 0;
	//һ��д��
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}


int main8()
{
	char arr[] = "abcdef";
	
	//strlen ͳ�Ƶ���\0֮ǰ���ֵ��ַ�����
	
	int len = my_strlen(arr);

	printf("%zd\n", len);
	return 0;
}





int main7()
{
	/*
		ָ������
		1.ָ��+-����
		2.ָ��-ָ��
		3.ָ��Ĺ�ϵ����
	*/

	int arr[] = { 1,2,3,4,5 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	int* parr = arr;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *(parr + i));
	}
	printf("\n");

	//ָ��-ָ��(��ַ-��ַ)ǰ��������ָ��ָ��ͬһ��ռ�
	//�õ��ľ���ֵ��ָ���ָ��֮���Ԫ�ظ���
	int ret = &arr[4] - &arr[0];
	printf("%d\n", ret);

	return 0;
}


int main6()
{
	/*
		const ����ָ��
		1.const��*�ŵ���ߣ����Ƶ���ָ�����ָ��Ķ���,���ǿ�������ָ���������
		2.const��*�ŵ��ұߣ����Ƶ���ָ������������ǿ����޸�ָ�����ָ��Ķ���
	*/
	int n = 100;
	int m = 200;

	const int* p = &n;
	//*p = 2;//���ܸ�
	printf("%d\n", *p);

	p = &m;//���Ը�
	return 0;
}

int main5()
{

	const int n = 100;
	//n = 20;
	//printf("%d\n", n);
	//��const���α����󣬸ñ������ܱ��޸�
	
	const int* p = &n;
	//*p = 20;//��ָ��ĵ���
	printf("%d\n", *p);
	//ͨ��ָ��ķ�ʽȷʵ���Ըĵ������Ǳ����ǲ��뱻�ĵģ���ô�죿
	//�ܼ򵥣��Ѹ�ָ�����Ҳ��������������Ҳ�޷��޸�

	
	return 0;
}




int main4()
{
	int arr[] = { 1,2,3,4,5 };
	
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;

	//for (i = 0; i < sz; i++);
	//{
	//	//�±귽ʽ��������
	//	printf("%d ", i);
	//}
	
	
	int* ptr = arr;//����������������Ԫ�صĵ�ַ
	for (i = 0; i < sz; i++)
	{
		//ָ�뷽ʽ��������
		printf("%d ", *(ptr + i));
	}

	return 0;
}




int main3()
{
	//ָ��+-����
	int n = 0x11223344;
	int* p = &n;
	char* pc = &n;

	printf("p    = %p\n", p);
	printf("p+1  = %p\n", p+1);

	printf("pc   = %p\n", pc);
	printf("pc+1 = %p\n", pc+1);

	/*
		ָ����������������
		ָ�����;����ˣ�ָ��+1��-1������ʱ��һ�����������ֽڣ�ָ��Ĳ�����
		��+n/-n ����n��ָ��ֵ��
	*/

	return 0;
}

int main2()
{
	//ָ�����͵����壿
	int n = 0x11223344;//����4���ֽ�
	int* p = &n;
	//*p = 0;//�ı�4���ֽ�

	//�������char*�����أ�
	char* pc = &n;//�ܷ���n�ĵ�ַ���ǿ��Եģ���Ϊ����4���ֽ�
	*pc = 0;
	/*
		�ܽ᣺
		1.ָ���������������
		2.ָ�����;�����ָ���ڽ����ò���ʱ��Ȩ�ޣ�Ҳ����һ�ν����÷��ʼ����ֽ�
	*/

	return 0;
}

int main1()
{
	int num = 10;
	int* p = &num;
	
	char ch = 'w';
	char* pc = &ch;

	//ָ������Ĵ�С��
	printf("%d\n", sizeof(p));
	printf("%d\n", sizeof(pc));
	
	//��X86������char*��int*��ָ���������4���ֽڣ�
	//��Ϊ��ָ�������Ϊ�˴�ŵ�ַ��
	//��ָ������Ĵ�С��ȡ���ڴ��һ����ַ��Ҫ���Ŀռ��
	//X86����������32��0��1��ɶ��������У��Ǵ�Ÿõ�ַ����Ҫ�Ŀռ����4���ֽ�
	//��X64����8���ֽ�

	/*
		�ܽ᣺
		1.��X86������ָ�������С����4���ֽ�
		2.��X64������ָ�������С����8���ֽ�
		ע��ָ������Ĵ�С���������޹صģ�����ͬƽ̨�¶���ͬ�����ֽ�
	*/
	printf("%zd\n", sizeof(char*));

	return 0;
}