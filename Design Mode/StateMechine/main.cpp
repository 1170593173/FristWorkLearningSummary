#include<iostream>
#include"War_State.h"
#include"current_state.h"
using namespace std;

/*代码运行流程：
首先创建war的对象，该对象中包含了各个具体状态的基类指针，可以动态指向各个状态
首先将基类指针指向了对象ProphaseState；
再调用基类指针对调用基类中的虚函数，也就是调用ProphaseState对象的CurrentState，在具体状态类中进行状态执行；
一直如此执行下去，在满足某个状态时，指针就将指向下个对象；继续上面的状态执行与转移；

核心就是war这个类，帮助完成了封装以及接口的定义；
*/






int main() {
	War *war = new War(new ProphaseState());
	for (int i = 1; i < 40; i += 5)
	{
		war->SetDays(i);
		war->GetState();
	}
	delete war;
	return 0;

}