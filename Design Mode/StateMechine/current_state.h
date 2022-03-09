#pragma once
#include"War_State.h"
#include<iostream>
using namespace std;
//ս������
class EndState : public State
{
public:
	void CurrentState(War *war) { End(war); }
	void End(War *war) //�����׶εľ�����Ϊ
	{
		cout << "ս������" << endl;
	}
	
};
//����
class AnaphaseState : public State
{
public:
	void Anaphase(War *war) //���ڵľ�����Ϊ
	{
		if (war->GetDays() < 30)
			cout << "��" << war->GetDays() << "�죺ս�����ڣ�˫��ƴ��һ��" << endl;
		else
		{
			war->SetState(new EndState());
			war->GetState();
		}
	}
	void CurrentState(War *war) { Anaphase(war); }
};
//����
class MetaphaseState : public State
{
public:
	void Metaphase(War *war) //���ڵľ�����Ϊ
	{
		if (war->GetDays() < 20)
			cout << "��" << war->GetDays() << "�죺ս�����ڣ�������ֽ׶Σ�˫���������" << endl;
		else
		{
			war->SetState(new AnaphaseState());
			war->GetState();
		}
	}
	void CurrentState(War *war) { Metaphase(war); }
};
//ǰ��
class ProphaseState : public State
{
public:
	void Prophase(War *war)  //ǰ�ڵľ�����Ϊ
	{
		if (war->GetDays() < 10)
			cout << "��" << war->GetDays() << "�죺ս�����ڣ�˫������������������̽�Է�" << endl;
		else
		{
			war->SetState(new MetaphaseState());
			war->GetState();
		}
	}
	void CurrentState(War *war) { Prophase(war); }
};

/*
��State�����඼�̳���State��������Ӧ�ĺ���Ϊ�麯����
������State����Ϊwar�Ĳ��������и��ݲ�ͬ���͵����ֵ����Ӧ����stateָ��ָ��ͬ�ĵ��࣬�ֱ���ò�ͬ���еĴ�������
�����ĺô����ڣ�ÿ��״̬֮��û���κι�ϵ���κ�״̬��Ĵ���������ת�����������Ĵ������У������Ҫ���״̬��ֻ��Ҫ����State�����ʵ�ֶ�Ӧ�Ĵ�������

*/