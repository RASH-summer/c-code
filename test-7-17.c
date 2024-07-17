#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void swap(char* buf1, char* buf2, size_t len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		//交换字节
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}

void my_qsort(void* base, size_t num, size_t len, int (*cmp)(const void * p1, const void * p2))
{
	//模拟实现qsort
	int i = 0;
	for (i = 0; i < num; i++)
	{
		int j = 0;
		for (j = 0; j < num - i - 1; j++)
		{
			//排序
			if(cmp((char*)base+j*len, (char*)base+(j + 1)*len) > 0)
				swap((char*)base + j * len, (char*)base + (j + 1) * len, len);
		}
	}
}

//com_int是使用者写的
int cmp_int(const void* q1, const void* q2)
{
	return *(int*)q1 - *(int*)q2;
}

void print(int* arr, size_t sz)
{
	//排序完后打印
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}


void test1()
{
	//测试排序整形数据
	int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
	size_t sz = sizeof(arr) / sizeof(arr[0]);

	my_qsort(arr, sz, sizeof(arr[0]), cmp_int);

	print(arr, sz);

}


struct Stu
{
	char name[10];
	int age;
};

#include <string.h>

int cmp_name_sort(const void* p1, const void* p2)
{
	return strcmp(((struct Stu*)p1)->name, ((struct Stu*)p2)->name);
}

void test2()
{
	//测试排序结构体数据，排序字符串
	struct Stu arr2[] = { {"a",10} ,{"c", 9} ,{"b", 22}};
	size_t sz = sizeof(arr2) / sizeof(arr2[0]);
	my_qsort(arr2, sz, sizeof(arr2[0]), cmp_name_sort);
}

int main()
{
	//test1();
	test2();

	return 0;
}
