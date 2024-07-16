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
		qsort是库函数，也就是别人写出来的，让我们用，暂时称她为：程序员A
		但是程序员A在实现这个函数的时候，不可能知道别人用qsort来排序什么样类型的数据，所以它设计成了void*
	*/

	int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	printf("排序前:\n");
	print(arr, sz);
	qsort(arr, sz, sizeof(arr[0]), com_int);
	printf("排序后:\n");
	print(arr,sz);

	return 0;
}


int main2()
{
	// qsort 是库函数，可以用来排序任意类型的数据 
	// 参考文献：cplusplus.com

	/*
		该函数共有4个参数：
		void qsort (void* base, size_t num, size_t size,
            int (*compar)(const void* p1,const void* p1));
		
		第1个参数：void* base
		第2个参数：size_t num
		第3个参数：size_t size
		第4个参数：int (*compar)(const void p1*,const void* p2))

		第1个参数描述：指向待排序的起始地址
		第2个参数描述：待排序的元素个数
		第3个参数描述：待排序元素的数组元素的大小，单位是字节
		第4个参数描述：compar是一个函数指针，指向的函数能够比较2个元素

		第4个参数额外补充：
						p1指向的元素 == p2指向的元素，返回0
						p1指向的元素 < p2指向的元素，返回 <0 的数字
						p1指向的元素 > p2指向的元素，返回 >0 的数字
	*/

	//void* 也是一种指针类型 称为：通用的指针类型，意思就是 void*类型的指针变量可以接收任意数据类型的地址（指针垃圾桶，什么地址都可以放）

	//但是也有缺陷，比如++ 和 --等操作

	//int a = 9;
	//void* p = &a;

	//p++;
	//*p; // 解引用也不行



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

	printf("请输入2个操作数：");
	scanf("%d %d", &a, &b);
	ret = pf(a, b);
	printf("%d\n", ret);

	//通过pf指针去调用其所指向的函数，被调用的函数称为回调函数
}

int main1()
{
	/*
		回调函数？？

		回调函数是一个通过函数指针调用的函数
		把函数指针作为参数传递给另一个函数，当这个指针被用来调用其所指向的函数时，被调用函数就是回调函数。
		回调函数不是由该函数的实现方直接调用，而是在特定的时间或条件发生时由另外的一方调用。

	*/

	int input = 0;
	do {
		menu();
		printf("请选择：");
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
			printf("退出\n");
			break;
		default:
			printf("选择错误，重新输入\n");
			break;
		}

	} while (input);

	return 0;
}