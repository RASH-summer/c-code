#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int add(int x, int y)
{
	return x+y;
}
int main()
{
	/*
		函数指针变量

		什么是函数指针变量？？？

		函数指针是指针，是指向函数的指针，存放的是函数地址
	*/

	//printf("%p\n", &add);
	//printf("%p\n", add);


	//注：对于函数而言，&函数名和函数名都是函数的地址
	
	//用一下

	int (*pf)(int, int) = &add;
		
	//去掉变量名：剩下的是类型

	//使用pf来调用add

	int ret = (*pf)(2,3); // 还可以写成更简单的形式：pf(2,8);
	printf("%d\n", ret);

	return 0;
}


void test(int (*arr)[5], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	
	//二维数组传参，传递的是数组首元素（第一行的地址）的地址
	//形参的部分就可以写成指向第一行的数组指针
}

int main6()
{
	/*
		二维数组传参的本质
		二维数组名也是数组首元素的地址
		既然是地址，那形参的方式也可以写成指针？来试试
	*/
	int arr[3][5] = { {1,2,3,4,5}, {2,3,4,5,6},{3,4,5,6,7} };

	test(arr, 3, 5);

	
	return 0;
}
int main5()
{
	//为什么数组名和&数组名+1的效果不同?
	int arr[3] = { 0 };
	arr;//数组首元素地址 -> int *
	&arr;//数组的地址 -> int (*)[3];
	int(*p)[3] = &arr;
	
	return 0;
}



int main4()
{

	/*
		数组指针变量

		数组指针是指向数组的指针，其实就是指针，存放的是数组的地址
	*/

	int arr[5] = { 0 };

	//ptr是数组指针 这里的方括号&圆括号不能省略
	int(*ptr)[5] = &arr;//注：这里&arr是数组的地址

	//练习一下吧
	char* ch[8];
	char* (*p2)[8] = &ch;//p2是数组指针

	//注：把指针变量名去掉剩下的是类型

	return 0;
}



int main3()
{
	//字符指针变量使用来存放字符变量的地址

	char ch = 'w';
	char* pc = &ch; //pc 就是字符指针变量

	const char* str = "abcdefghi";//str存放的难道是"abcdefghi"？肯定不是嘛，因为它存不下
	//指针变量的大小要么4个字节要么8个字节
	//str其实存储的是首字符a的地址，来试一下
	//printf("%c\n", *str);

	//"abcdefghi"常量字符串是不能修改的，再试一下
	//*str = "aaaa";//这样子代码最后会挂掉的

	//既然不能改，那就直接上const，这样一看就知道不能改了
	
	printf("%s\n", str);

	return 0;
}


int main2()
{
	/*
		指针数组？
		存放指针(地址)的数组，叫指针数组！
		指针数组中的每个元素都是用来存放指针（地址）的
	*/
	
	//指针数组模拟二维数组
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 2,3,4,5,6 };
	int arr3[] = { 3,4,5,6,7 };

	int* parr[3] = { arr1, arr2, arr3 };//数组名是首元素的地址

	int i = 0;
	for (i = 0; i < 3; i++)
	{
		int j = 0;
		for (j = 0; j <5 ; j++)
		{
			printf("%d ", parr[i][j]);
		}
		printf("\n");
	}

	return 0;
}







int main1()
{
	//二级指针
	//什么是二级指针？？

	int a = 2; //整型变量a 占用4个字节的空间有自己的内存地址
	
	//p的类型是：int*
	int* p = &a;//指针变量p 占4个或8个字节 也有自己的地址

	int** ptr = &p;//ptr的类型是 int**
	//ptr也是指针变量，因为它也是用来存放地址的，它是二级指针
	//为啥要2颗星？因为有1颗星表示ptr是指针，另1颗表示它指向p指针变量的类型是int*


	//通过二级指针变量ptr找到a,对二级指针变量解引用一次找到一级指针变量p然后再解引用一次就找到a了
	printf("%d\n", **ptr);

	//二级指针变量是用来存放一级指针变量的地址的！

	return 0;
}