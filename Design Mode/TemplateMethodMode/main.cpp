#include"TemplateMethod.h"

/*������Ҫ�����ĳһϸ�ڲ��һ�µĹ��̻�һϵ�в��裬
����������ڸ���ϸ�Ĳ�����ʵ�ֿ��ܲ�ͬ��ʱ��
����ͨ��������ģ�巽��ģʽ������*/

int main() {
	cout << "-------------------ѧ��A���Ծ�-------------------" << endl << endl;
	TestPaper *pStuA = new TestPaperA();
	pStuA->TestQuestion1();
	pStuA->TestQuestion2();
	pStuA->TestQuestion3();
	cout << endl << endl;
	cout << "------------------ѧ��B���Ծ�------------------" << endl << endl;
	TestPaper *pStuB = new TestPaperB();
	pStuB->TestQuestion1();
	pStuB->TestQuestion2();
	pStuB->TestQuestion3();
	system("pause");
	return 0;
}