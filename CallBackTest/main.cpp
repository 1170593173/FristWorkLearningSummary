#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "finance.h"
using namespace std;

/**
*�����ͳ��״������
**/
static int finance_result(int *a, int n);


/* *
*�ϰ��뿴���񱨱�
* */
void boss_read_finance(int *array, int n, int(*fp)(int*, int));


using namespace::std;
using namespace::zzf;
int main(int argc, char* argv[]) {

	int array[10] = { 1,2,3,4,5,6,7,8,9,10 };

	Boss boss;

	boss.readFianace(array, 10);

	return 0;


	////����һ����������
	//int array[10] = { 1,2,3,4,5,6,7,8,9,10 };
	////��Ϊ�������к�����Ҳ�ǵ�ַ����˶����β����Ǻ���ָ��Ļ������ʱ��ֱ�ӽ���ַ����ȥ�Ϳ����ˣ�
	////ע�⣺����ָ����ָ�����ĵ�ַ,����fp�ǵ�ַ����ô���õ�ʱ���Ȼ��Ҫ(*fp)
	////Ҳ��������д��
	////int (*fp)(int *a,int n);
	////fp = finance_result;
	////boss_read_finance(array,10,finance_result);

	//boss_read_finance(array, 10, finance_result);

	//return 0;
}

/* *
*�ϰ�鿴����״����ʵ�֣���������һ������ָ�룬
* */
void boss_read_finance(int* array, int n, int(*fp)(int* a, int n)) {
	//�����ϰ���˵�����ǲ���Ҫȥ�˽���񲿵ľ���ʵ�ֵĹ��̣�ֻҪ���������
	//������������ǶԺ�����װ
	int result = (*fp)(array, n);
	printf("caculate result:%d\n", result);
}

/* **
*������㱨��ľ���ʵ��
* */
static int finance_result(int* a, int n) {
	int result = 0;
	int i = 0;
	for (i = 0; i < n; i++) {
		result += *(a + i);
	}
	return result;
}