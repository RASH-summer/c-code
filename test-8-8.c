#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>



int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	
	int product = a * b;
	
	//����С������
	//˼·���������ĳ˻� / ���Լ��

	//step1:������Լ��
	
	while (b>0)
	{
		int c = a % b;
		a = b;
		b = c;
	}

	product /= a;
	printf("��С�������ǣ�%d\n", product);

	return 0;
}




int main6()
{
	//������ԼΪ����ʽ
	int n = 0;//����
	int m = 0;//��ĸ

	printf("����һ��������");
	scanf("%d/%d", &n, &m);

	//��m����start����Ϊշת�����m�ͻ���0
	int start = m;

	//˼·��step1����������Ӻͷ�ĸ�����Լ��
			//step2�����ӷ�ĸ�ֱ�������Լ��
	
	//������Լ��
	while (m > 0)
	{
		int c = n % m;
		n = m;
		m = c;
	}
	//printf("%d\n", n);

	//Լ��
	int r = n;//��Ϊ�����n�Ѿ������Լ���ˣ�������Ҫ��ʱ�����洢
	n /= n;
	start /= r;
	printf("�����Ϊ��%d/%d\n", n, start);

	return 0;
}


int main5()
{
	//�������Լ��
	int a = 0;
	int b = 0;
	
	scanf("%d %d", &a, &b);
	int c = 0;
	//շת���
	while (b != 0)//ѭ������ -- �ж������Ƿ�Ϊ0
	{
		c = a % b;//�õ�����
		//����
		a = b;
		b = c;
	}
	printf("���Լ���ǣ�%d\n",a);
	return 0;
}

int main4()
{
	float n = 0;
	float max = 0;


	printf("����һ�����֣�");
	scanf("%f", &n);
	while (n > 0)
	{
		//�Ƚϳ���������
		if (n > max)
			max = n;
		printf("����һ�����֣�");
		scanf("%f", &n);

	}
	printf("��������ֵ�ǣ�%.2f\n", max);
	return 0;
}


int main3()
{
	int i = 0;
	//for (i = 1; i <= 128; i *= 2)
	//	printf("%d ", i);
	//printf("\n");
	//printf("-----------------------\n");//�ָ���
	//for (i = 9384; i > 0; i /= 10)
	//	printf("%d ", i);
	//printf("\n");


	//for (i = 10; i >= 1; i /= 2)
	//	printf("%d ", i++);//������ѭ����
	//
	i = 10;
	//while (i>=1)
	//{
	//	printf("%d ", i++);
	//	i /= 2;
	//}


	int sum = 0;
	for (i = 0; i < 10; i++)
	{
		if (i % 2)
			continue;
		sum += i;
	}
	printf("%d\n", sum);



	return 0;
}

int main2()
{
	int i = 0;

	//while (i<10)
	//	printf("%d ", i);//��ѭ���ˣ���Ϊѭ������iû�б仯

	//for (; i < 10;)
	//	printf("%d ", i);//Ҳ����ѭ��

	do
	{
		printf("%d ", i);//Ҳ����ѭ��
	}while (i<10);


	return 0;
}



int main1()
{
	int i = 0;
	int j = 0;
	/*for (i = 5,j = i - 1; i > 0, j> 0; --i, j = i - 1)
	{
		printf("%d ", i);
	}*/

	//for (i = 0; i < 10; i++)
	//	printf("%d ", i);
	//printf("\n");

	//for (i = 0; i < 10; ++i)
	//	printf("%d ", i);
	//printf("\n");
	
	//for (i = 0; i++ < 10;)//ע�������Ǻ���++����ʹ�ú�++������i=9��ʱ����������Ȼ�����ѭ���壬��ʱi�Ѿ�++���10
	//	printf("%d ", i);
	//printf("\n");
	//


	return 0;
}
