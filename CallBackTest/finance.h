#pragma once
#ifndef __FINANCE_H__
#define __FINANCE_H__

namespace zzf {

#include<iostream>
	using namespace::std;
	/* *
	*����һ�����������Ľӿ�
	* */
	class CallBack {
	public:
		virtual void setFinanceResult(int result)  const = 0;
	};

	/* *
	*����
	ר�����ڼ�������
	* */
	class Finance {
	public:
		Finance(CallBack* mCallBack2) :mCallBack(mCallBack2) {
			cout << "finance constructor" << endl;
		}
		~Finance() {
			cout << "finance destructor" << endl;
		}
		void caculateFinance(int * a, int n) {
			int result = 0;
			for (int i = 0; i < n; i++) {
				result += *(a + i);
			}
			if (mCallBack != NULL) {
				cout << "result:" << result << endl;
				mCallBack->setFinanceResult(result);
			}
		}
	private:
		CallBack* mCallBack;
	};


	/* *
	*�ϰ壬ʵ�ֽӿڣ��������
	* */
	class Boss :public CallBack {
	public:
		Boss() {
			//���ӿ�ʵ�����󣬴��ݸ��ƣ������
			mFinace = new Finance(this);
			cout << "boss constructor" << endl;
		}
		~Boss() {
			delete mFinace;
			cout << "boss destructor" << endl;
		}
		//�鿴����ĺ���
		void readFianace(int *array, int n) {
			cout << "boss readFianace" << endl;
			mFinace->caculateFinance(array, n);
		}
		//ʵ�ֺ�Ļص�������������������������ջص���ֵ��
		void setFinanceResult(int result) const {
			cout << "caculate result:" << result << endl;
		}
	private:
		Finance *mFinace;
	};
}
#endif

/*��ʵ��������ܹ������ǶԻص��и�����̵���ʶ��
�����ϰ���鿴����(�����Լ�����,�����ڣ������)
����֪ͨ������Ҫ�鿴����(���м���Ĺ��̣������ڣ��������ڲ�)
�����������֮�󣬷��ظ��ϰ�(�ص��ĺ����ڣ�����ڲ�)
Ҳ���ǻص����ǰѲ���Ҫ�Լ�����Ķ����ŵ������ȥ��Ȼ����䴦�����֮���ٷ��ظ����õ��࣮*/