#include<iostream>
#include"War_State.h"
#include"current_state.h"
using namespace std;

/*�����������̣�
���ȴ���war�Ķ��󣬸ö����а����˸�������״̬�Ļ���ָ�룬���Զ�ָ̬�����״̬
���Ƚ�����ָ��ָ���˶���ProphaseState��
�ٵ��û���ָ��Ե��û����е��麯����Ҳ���ǵ���ProphaseState�����CurrentState���ھ���״̬���н���״ִ̬�У�
һֱ���ִ����ȥ��������ĳ��״̬ʱ��ָ��ͽ�ָ���¸����󣻼��������״ִ̬����ת�ƣ�

���ľ���war����࣬��������˷�װ�Լ��ӿڵĶ��壻
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