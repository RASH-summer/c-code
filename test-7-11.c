#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>


void menu()
{
	//功能菜单
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
	//函数指针-转移表-计算器
	int(*pfarr[])(int, int) = { 0, Add, Sub, Mul, Div };//用函数指针数组存起来，0是用来占位的
	int input = 0;
	int a = 0;
	int b = 0;
	int ret = 0;
	do {
		menu();
		printf("请选择:");
		scanf("%d", &input);
		if (input >= 1 && input <= 4)
		{
			printf("请输入2个操作数：");
			scanf("%d %d", &a, &b);
			ret = pfarr[input](a,b);//根据input的值来调用对应的函数
			printf("%d\n", ret);
		}
		else if (input == 0)
		{
			printf("退出!\n");
			break;
		}
		else
		{
			printf("选择错误，重新选择\n");
		}

		
	} while (input);
	return 0;

	/*
		用函数指针数组来改造刚才的代码，如果要加其它的功能只需要改变菜单，再添加新的函数就好了，不需要写重复的代码，代码量减少了很多
		当然这里是不支持小数的计算的
	*/
}

int main4()
{
	//实现一个建议版本的计算器
	int input = 0;
	int a = 0;
	int b = 0;
	int ret = 0;
	do {
		menu();
		printf("请选择:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("请输入2个操作数：");
			scanf("%d %d", &a, &b);
			ret = Add(a, b);
			printf("%d\n", ret);
			break;
		case 2:
			printf("请输入2个操作数：");
			scanf("%d %d", &a, &b);
			ret = Sub(a, b);
			printf("%d\n", ret);
			break;
		case 3:
			printf("请输入2个操作数：");
			scanf("%d %d", &a, &b);
			ret = Mul(a, b);
			printf("%d\n", ret);
			break;
		case 4:
			printf("请输入2个操作数：");
			scanf("%d %d", &a, &b);
			ret = Div(a, b);
			printf("%d\n", ret);
			break;
		case 0:
				break;
		default:
			printf("选择错误，从新输入\n");
		}
	} while (input);
	return 0;

	/*
		这是一个简单计算器的实现，如果以后想要给它加其它功能的话switch语句里面的，
		代码会变得很长很长，假如添加5个功能那就会一直到case9 
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

//函数指针数组 
int main3()
{
	//函数指针 - 是数组，数组中存放的都是函数指针

	int (*p1)(int, int) = Add;
	int (*p2)(int, int) = Sub;

	//想要把pq和p2都存在一个数组里面

	int (*parr[4])(int, int) = { Add,Sub };//parr是一个函数指针数组

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


// typedef 可以把复杂类型简单化
typedef int* ptr_t;
typedef void(*pf_t)(int);//pf_t 是类型名

int main1()
{
	int* p;
	ptr_t ptr;
	
	pf_t p1;
	//void(*p3)(int); //函数指针

	pf_t signal(int, pf_t);

	
	return 0;
}