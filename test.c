#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#define NDEBUG
#include <assert.h>



//size_t�������޷��ŵ�����
size_t my_strlen(const char* str)
{
	assert(str);
	size_t count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}
int main6()
{
	//strlen ģ��ʵ��

	char arr[] = "abcdef";
		
	size_t ret = my_strlen(arr);
	printf("%zd\n", ret);

	return 0;
}


void swap(int* x, int* y)
{
	int z = *x;
	*x = *y;
	*y = z;
}


int main5()
{
	//ָ���ʹ�úʹ�ַ����

	//дһ�������������������ͱ���
	int a = 10;
	int b = 20;
	printf("����ǰ��a=%d b=%d\n", a, b);

	//��ֵ����
	//��ֵ���ã�����ʵ�δ��ݸ��βκ��β���ʵ�ε�һ����ʱ����,�β��ж����Ŀռ�
	//���Զ��βε��޸Ĳ���Ӱ��ʵ��
	//swap(a,b);

	//��ַ����
	swap(&a,&b);

	printf("������a=%d b=%d\n", a, b);



	return 0;
}



int main4()
{
	//assert ����

	//֮ǰ�����ʹ��ָ��ǰӦ�ü��������Ч��

	//assert.h ͷ�ļ��ж����˺�assert(),����������ʱȷ���������ָ����������������ϣ�
	//�ͱ���������ֹ���У�����걻��Ϊ������

	int* p = NULL;//��ָ��
	//assert(p != NULL);//��������������ʱ�򣬳���ᱨ��

	int a = 19;
	int* ret = &a;
	assert(ret != NULL);//������������ʱ�򣬳��򲻻ᷢ���κ���

	//assert()���С����ع��ܡ�

	//����Ҫ��assert���ԣ���#include <assert.h>���ǰ������һ���� NDEBUG
	//�׻��������ǲ����������Թرգ����ÿ��Կ�����

	return 0;
}


int main3()
{
	int arr[] = { 1,2,3,4,5 };
	int* p = arr;
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *(p + i));
	}
	//���������ʱ��p�Ѿ��Ǹ�Ұָ����

	p = NULL;

	//ע������ջ�ռ��ַ�����������Ұָ�룡����


	return 0;
}

int main2()
{
	int* ptr = NULL;//��ָ��
	


	return 0;
}

int main1()
{
	//ָ��һ��Ҫ��ʼ�������Ա���Ұָ��ĳ���
	int n = 10;
	int* p = &n;//��ʼ��

	//�����ȷ��ָ���ָ��������Գ�ʼ��Ϊ��NULL
	int* ptr = NULL;//��ָ��

	//NULL��������0
	
	//0Ҳ�ǵ�ַ�����Ǹõ�ַ�޷�ʹ�ã���д�õ�ַ�ᱨ��

	//С��ָ���Խ�磡һ���������ڴ���������Щ�ռ䣬ͨ��ָ��Ҳ��ֻ�ܷ�����Щ�ռ䣻
	//�����˾���Խ����ʣ�


	//ָ���������ʹ��ʱ��Ӧ�ü�ʱ��ΪNULL��ʹ��ָ��ǰ�ü��������Ч�ԣ�

	if (ptr != NULL)
	{
		*ptr = 10;
	}
	else
	{
		;//�����
	}

	//������if�����ָ�����Ч�ԣ�����̫�鷳��

	return 0;
}