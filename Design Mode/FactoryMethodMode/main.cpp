#include"FactoryMethod.h"

int main() {
	IFactory* factroy = new UndergraduateFactory();
	baseClass *Person= factroy->createInstence();
	
	Person->BuyRice();
	Person->Sweep();
	Person->Wash();



	/*һ���ǹ���C++��̬��һЩ˼�����빤������ģʽ�޹�*/
	/*
	�������һ��˼����
	baseClass��Ϊ���࣬Undergraduate��Ϊ�̳л���ĵ����࣬
	������Ҫ���̳еĺ�������������������Ϊ���麯����
	���� �����������¶���ĺ��������û����ָ���ǲ���ʹ������Ļ���û�еķ����ģ�
	������߼������

	baseClass *Person = new Undergraduate();
	Person->Test();*/

	/*������ø��෽��*/
	Undergraduate*UnPerson = new Undergraduate();
	UnPerson->baseClass::BuyRice();
	UnPerson->BuyRice();
	//Person->Test();
	system("pause");
	return 0;
}