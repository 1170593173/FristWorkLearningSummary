#pragma once
#ifndef __FINANCE_H__
#define __FINANCE_H__

namespace zzf {

#include<iostream>
	using namespace::std;
	/* *
	*定义一个ｃａｌｌｂａｃｋ的接口
	* */
	class CallBack {
	public:
		virtual void setFinanceResult(int result)  const = 0;
	};

	/* *
	*财务：
	专门用于计算结果的
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
	*老板，实现接口ｃａｌｌｂａｃｋ
	* */
	class Boss :public CallBack {
	public:
		Boss() {
			//将接口实例化后，传递给Ｆｉｎａｎｃｅ
			mFinace = new Finance(this);
			cout << "boss constructor" << endl;
		}
		~Boss() {
			delete mFinace;
			cout << "boss destructor" << endl;
		}
		//查看财务的函数
		void readFianace(int *array, int n) {
			cout << "boss readFianace" << endl;
			mFinace->caculateFinance(array, n);
		}
		//实现后的回调函数，这个函数就是用来接收回调的值的
		void setFinanceResult(int result) const {
			cout << "caculate result:" << result << endl;
		}
	private:
		Finance *mFinace;
	};
}
#endif

/*其实这个案例能够让我们对回调有更加深刻的认识：
１：老板想查看财务(调用自己函数,函数在ｂｏｓｓ内)
２：通知财务，我要查看报表(进行计算的过程，函数在ｆｉｎａｎｃｅ内部)
３：财务算好之后，返回给老板(回调的函数在ｂｏｓｓ内部)
也就是回调就是把不需要自己处理的东西放到别的类去，然后等其处理完毕之后，再返回给调用的类．*/