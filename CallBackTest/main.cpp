#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "finance.h"
using namespace std;

/**
*财务的统计状况函数
**/
static int finance_result(int *a, int n);


/* *
*老板想看财务报表
* */
void boss_read_finance(int *array, int n, int(*fp)(int*, int));


using namespace::std;
using namespace::zzf;
int main(int argc, char* argv[]) {

	int array[10] = { 1,2,3,4,5,6,7,8,9,10 };

	Boss boss;

	boss.readFianace(array, 10);

	return 0;


	////定义一个数组数据
	//int array[10] = { 1,2,3,4,5,6,7,8,9,10 };
	////因为Ｃ语言中函数名也是地址，因此对于形参数是函数指针的话，这个时候直接将地址传进去就可以了；
	////注意：函数指针是指向函数的地址,对于fp是地址，那么调用的时候固然需要(*fp)
	////也可以这样写：
	////int (*fp)(int *a,int n);
	////fp = finance_result;
	////boss_read_finance(array,10,finance_result);

	//boss_read_finance(array, 10, finance_result);

	//return 0;
}

/* *
*老板查看财务状况的实现，参数中有一个函数指针，
* */
void boss_read_finance(int* array, int n, int(*fp)(int* a, int n)) {
	//对于老板来说，他是不需要去了解财务部的具体实现的过程，只要结果就行了
	//这就有助于我们对函数封装
	int result = (*fp)(array, n);
	printf("caculate result:%d\n", result);
}

/* **
*财务计算报表的具体实现
* */
static int finance_result(int* a, int n) {
	int result = 0;
	int i = 0;
	for (i = 0; i < n; i++) {
		result += *(a + i);
	}
	return result;
}