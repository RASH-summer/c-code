#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <string.h>

int main9()
{
	//野指针
	//概念：野指针就是指针指向的位置是不可知的（随机的、不正确的、没有明确限制的）


	int* p;//局部变量不初始化，得到的是随机值
	//*p = 20;
	

	return 0;
}



int main9()
{
	//指针的关系运算：实际就是指针（地址）比较大小

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
	//指针实现
	while (*str != '\0')
	{
		str++;
	}
	return str - start;
}

int my_strlen1(char* str)
{
	int count = 0;
	//一般写法
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
	
	//strlen 统计的是\0之前出现的字符个数
	
	int len = my_strlen(arr);

	printf("%zd\n", len);
	return 0;
}





int main7()
{
	/*
		指针运算
		1.指针+-整数
		2.指针-指针
		3.指针的关系运算
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

	//指针-指针(地址-地址)前提是两个指针指向同一块空间
	//得到的绝对值是指针和指针之间的元素个数
	int ret = &arr[4] - &arr[0];
	printf("%d\n", ret);

	return 0;
}


int main6()
{
	/*
		const 修饰指针
		1.const在*号的左边，限制的是指针变量指向的对象,但是可以修饰指针变量本身
		2.const在*号的右边，限制的是指针变量本身，但是可以修改指针变量指向的对象
	*/
	int n = 100;
	int m = 200;

	const int* p = &n;
	//*p = 2;//不能改
	printf("%d\n", *p);

	p = &m;//可以改
	return 0;
}

int main5()
{

	const int n = 100;
	//n = 20;
	//printf("%d\n", n);
	//被const修饰变量后，该变量不能被修改
	
	const int* p = &n;
	//*p = 20;//用指针改掉它
	printf("%d\n", *p);
	//通过指针的方式确实可以改掉，但是本质是不想被改的，怎么办？
	//很简单，把该指针变量也限制起来！让它也无法修改

	
	return 0;
}




int main4()
{
	int arr[] = { 1,2,3,4,5 };
	
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;

	//for (i = 0; i < sz; i++);
	//{
	//	//下标方式访问数组
	//	printf("%d ", i);
	//}
	
	
	int* ptr = arr;//数组名就是数组首元素的地址
	for (i = 0; i < sz; i++)
	{
		//指针方式访问数组
		printf("%d ", *(ptr + i));
	}

	return 0;
}




int main3()
{
	//指针+-整数
	int n = 0x11223344;
	int* p = &n;
	char* pc = &n;

	printf("p    = %p\n", p);
	printf("p+1  = %p\n", p+1);

	printf("pc   = %p\n", pc);
	printf("pc+1 = %p\n", pc+1);

	/*
		指针的类型是有意义的
		指针类型决定了，指针+1或-1操作的时候，一次跳过几个字节（指针的步长）
		（+n/-n 跳过n个指向值）
	*/

	return 0;
}

int main2()
{
	//指针类型的意义？
	int n = 0x11223344;//放满4个字节
	int* p = &n;
	//*p = 0;//改变4个字节

	//那如果是char*类型呢？
	char* pc = &n;//能放下n的地址吗？是可以的，因为都是4个字节
	*pc = 0;
	/*
		总结：
		1.指针类型是有意义的
		2.指针类型决定了指针在解引用操作时的权限，也就是一次解引用访问几个字节
	*/

	return 0;
}

int main1()
{
	int num = 10;
	int* p = &num;
	
	char ch = 'w';
	char* pc = &ch;

	//指针变量的大小？
	printf("%d\n", sizeof(p));
	printf("%d\n", sizeof(pc));
	
	//在X86环境下char*和int*的指针变量都是4个字节？
	//因为：指针变量是为了存放地址的
	//那指针变量的大小是取决于存放一个地址需要多打的空间吧
	//X86环境下是由32个0或1组成二进制序列，那存放该地址所需要的空间就是4个字节
	//而X64则是8个字节

	/*
		总结：
		1.在X86环境下指针变量大小都是4个字节
		2.在X64环境下指针变量大小都是8个字节
		注：指针变量的大小与类型是无关的，在相同平台下都是同样的字节
	*/
	printf("%zd\n", sizeof(char*));

	return 0;
}