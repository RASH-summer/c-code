#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#define NDEBUG
#include <assert.h>



//size_t类型是无符号的整形
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
	//strlen 模拟实现

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
	//指针的使用和传址调用

	//写一个函数，交换两个整型变量
	int a = 10;
	int b = 20;
	printf("交换前：a=%d b=%d\n", a, b);

	//传值调用
	//传值调用，函数实参传递给形参后，形参是实参的一份临时拷贝,形参有独立的空间
	//所以对形参的修改不会影响实参
	//swap(a,b);

	//传址调用
	swap(&a,&b);

	printf("交换后：a=%d b=%d\n", a, b);



	return 0;
}



int main4()
{
	//assert 断言

	//之前提过，使用指针前应该检查它的有效性

	//assert.h 头文件中定义了宏assert(),用于在运行时确保程序符合指定条件，如果不符合；
	//就报错，并且终止运行！这个宏被称为：断言

	int* p = NULL;//空指针
	//assert(p != NULL);//当条件不成立的时候，程序会报错

	int a = 19;
	int* ret = &a;
	assert(ret != NULL);//当条件成立的时候，程序不会发生任何事

	//assert()还有“开关功能”

	//不需要在assert断言，在#include <assert.h>语句前，定义一个宏 NDEBUG
	//俗话来讲就是不想用它可以关闭，想用可以开启！

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
	//当来到这的时候，p已经是个野指针了

	p = NULL;

	//注：返回栈空间地址，很容易造成野指针！！！


	return 0;
}

int main2()
{
	int* ptr = NULL;//空指针
	


	return 0;
}

int main1()
{
	//指针一定要初始化，可以避免野指针的出现
	int n = 10;
	int* p = &n;//初始化

	//如果不确定指针该指向哪里，可以初始化为：NULL
	int* ptr = NULL;//空指针

	//NULL本质上是0
	
	//0也是地址，但是该地址无法使用，读写该地址会报错

	//小心指针的越界！一个程序向内存申请了哪些空间，通过指针也就只能访问哪些空间；
	//超出了就是越界访问！


	//指针变量不再使用时，应该及时置为NULL，使用指针前该检查它的有效性！

	if (ptr != NULL)
	{
		*ptr = 10;
	}
	else
	{
		;//空语句
	}

	//但是用if语句检查指针的有效性，还是太麻烦了

	return 0;
}