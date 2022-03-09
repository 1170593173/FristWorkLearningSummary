#pragma once
#include"War_State.h"
#include<iostream>
using namespace std;
//战争结束
class EndState : public State
{
public:
	void CurrentState(War *war) { End(war); }
	void End(War *war) //结束阶段的具体行为
	{
		cout << "战争结束" << endl;
	}
	
};
//后期
class AnaphaseState : public State
{
public:
	void Anaphase(War *war) //后期的具体行为
	{
		if (war->GetDays() < 30)
			cout << "第" << war->GetDays() << "天：战争后期，双方拼死一搏" << endl;
		else
		{
			war->SetState(new EndState());
			war->GetState();
		}
	}
	void CurrentState(War *war) { Anaphase(war); }
};
//中期
class MetaphaseState : public State
{
public:
	void Metaphase(War *war) //中期的具体行为
	{
		if (war->GetDays() < 20)
			cout << "第" << war->GetDays() << "天：战争中期，进入相持阶段，双发各有损耗" << endl;
		else
		{
			war->SetState(new AnaphaseState());
			war->GetState();
		}
	}
	void CurrentState(War *war) { Metaphase(war); }
};
//前期
class ProphaseState : public State
{
public:
	void Prophase(War *war)  //前期的具体行为
	{
		if (war->GetDays() < 10)
			cout << "第" << war->GetDays() << "天：战争初期，双方你来我往，互相试探对方" << endl;
		else
		{
			war->SetState(new MetaphaseState());
			war->GetState();
		}
	}
	void CurrentState(War *war) { Prophase(war); }
};

/*
各State的子类都继承与State，其中相应的函数为虚函数，
将各个State的作为war的参数，其中根据不同类型的入参值，对应控制state指针指向不同的的类，分别调用不同类中的处理函数；
这样的好处在于：每个状态之间没有任何关系，任何状态类的处理函数都可转换到另外的类的处理函数中；如果需要添加状态，只需要集成State类进行实现对应的处理函数；

*/