#include"TemplateMethod.h"

/*当我们要完成在某一细节层次一致的过程或一系列步骤，
但其个别步骤在更详细的层面上实现可能不同的时候，
我们通常考虑用模板方法模式来处理*/

int main() {
	cout << "-------------------学生A的试卷-------------------" << endl << endl;
	TestPaper *pStuA = new TestPaperA();
	pStuA->TestQuestion1();
	pStuA->TestQuestion2();
	pStuA->TestQuestion3();
	cout << endl << endl;
	cout << "------------------学生B的试卷------------------" << endl << endl;
	TestPaper *pStuB = new TestPaperB();
	pStuB->TestQuestion1();
	pStuB->TestQuestion2();
	pStuB->TestQuestion3();
	system("pause");
	return 0;
}