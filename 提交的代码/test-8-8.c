#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>



int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	
	int product = a * b;
	
	//求最小公倍数
	//思路：两个数的乘积 / 最大公约数

	//step1:求出最大公约数
	
	while (b>0)
	{
		int c = a % b;
		a = b;
		b = c;
	}

	product /= a;
	printf("最小公倍数是：%d\n", product);

	return 0;
}




int main6()
{
	//将分数约为最简分式
	int n = 0;//分子
	int m = 0;//分母

	printf("输入一个分数：");
	scanf("%d/%d", &n, &m);

	//将m交给start，因为辗转相除后m就会变成0
	int start = m;

	//思路：step1：计算出分子和分母的最大公约数
			//step2：分子分母分别除以最大公约数
	
	//求出最大公约数
	while (m > 0)
	{
		int c = n % m;
		n = m;
		m = c;
	}
	//printf("%d\n", n);

	//约分
	int r = n;//因为这里的n已经是最大公约数了，所以需要临时变量存储
	n /= n;
	start /= r;
	printf("化简后为：%d/%d\n", n, start);

	return 0;
}


int main5()
{
	//计算最大公约数
	int a = 0;
	int b = 0;
	
	scanf("%d %d", &a, &b);
	int c = 0;
	//辗转相除
	while (b != 0)//循环条件 -- 判断余数是否不为0
	{
		c = a % b;//得到余数
		//交换
		a = b;
		b = c;
	}
	printf("最大公约数是：%d\n",a);
	return 0;
}

int main4()
{
	float n = 0;
	float max = 0;


	printf("输入一个数字：");
	scanf("%f", &n);
	while (n > 0)
	{
		//比较出最大的数字
		if (n > max)
			max = n;
		printf("输入一个数字：");
		scanf("%f", &n);

	}
	printf("输入的最大值是：%.2f\n", max);
	return 0;
}


int main3()
{
	int i = 0;
	//for (i = 1; i <= 128; i *= 2)
	//	printf("%d ", i);
	//printf("\n");
	//printf("-----------------------\n");//分隔符
	//for (i = 9384; i > 0; i /= 10)
	//	printf("%d ", i);
	//printf("\n");


	//for (i = 10; i >= 1; i /= 2)
	//	printf("%d ", i++);//这里死循环了
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
	//	printf("%d ", i);//死循环了，因为循环变量i没有变化

	//for (; i < 10;)
	//	printf("%d ", i);//也是死循环

	do
	{
		printf("%d ", i);//也是死循环
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
	
	//for (i = 0; i++ < 10;)//注意这里是后置++（先使用后++），当i=9的时候条件成立然后进入循环体，此时i已经++变成10
	//	printf("%d ", i);
	//printf("\n");
	//


	return 0;
}
