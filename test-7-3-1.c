#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>



//冒泡排序的核心思想：两两相邻的元素进行比较
void sort(int* arr, int len)
{
	//确定冒泡排序的趟数 n-1
	int i = 0;
	for (i = 0; i < len; i++)
	{
		//一趟冒泡排序
		int flag = 1; //假设数组已经是有序的了
		int j = 0;
		for (j = 0; j < len - i; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				//交换
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;//不是有序的
			}
		}
		if (flag == 1)
			break; //说明数组有序，跳出循环
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
	
	sort(arr, sz);//排为降序
	print_arr(arr, sz);

	return 0;
}


void print(int* arr)
{
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);//得不到数组元素的个数
	/*
		因为形参是数组首元素的地址
		4 / 4 = 1
		所以，应该是在主函数计算才能得到数组元素的个数
	
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
	//输入
	for (i = 0; i < sz; i++)
	{
		scanf("%d", ptr + i);
	}
	//输出
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *(ptr + i));
	}

	return 0;
}

int main1()
{
	//数组名的理解
	int arr[] = { 1,2,3,4,5 };
	printf("%p\n", arr);
	printf("%p\n", &arr[0]);

	//数组名就是数组首元素的地址?

	//printf("%zd\n", sizeof(arr));//如果这个说法成立，那么应该是4byte或者是8个byte
	//运行结果是20？

	/*
		补充：
		数组名是数组首元素的地址，但是有两个例外：
		1.sizeof(数组名)，这里的数组名表示整个数组，sizeof(数组名)计算的是整个数组的大小，单位是字节
		2.sizeof(&数组名），这里的数组名表示整个数组，&数组名取出的是整个数组的地址！
	*/

	printf("%p\n", &arr);//和首元素地址一样，为什么？？？
	/*
		首先它们是同一块内存空间，整个数组也是从首元素地址开始吧，所以它和首元素地址是一样的
		那有什么区别？
	*/

	printf("arr        ================= %p\n", arr);
	printf("arr + 1    ================= %p\n", arr + 1);
	printf("arr[0]     ================= %p\n", &arr[0]);
	printf("arr[0] + 1 ================= %p\n", &arr[0] + 1);

	printf("&arr[      ================= %p\n", &arr);
	printf("&arr + 1   ================= %p\n", &arr + 1);
	//注：数组的地址加上了1，居然跳过了20个字节（也就是加了20个字节）加上了16进制的0x14

	//0000 0000 0000 0000 0000 0000 0001 0100
	//0x 00 00 00 14

	return 0;
}