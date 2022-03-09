#pragma once
#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;
/*����Ϸ�У�ͨ�����������Ʋ�ͬ��vip���*/

/*����ӿ�*/
class Play {
public:
	virtual void Play1() = 0;
	virtual void Play2() = 0;
	virtual void Play3() = 0;
};

/*��������*/
class Player : public Play {
public:
	void Play1() {
		cout << "��ͨս��" << endl;
	}
	void Play2() {
		cout << "����ս��" << endl;
	}
	void Play3() {
		cout << "����" << endl;
	}

};

/*����VIP0���*/
class ProxyPlayerVip0 :public Play
{
public:
	ProxyPlayerVip0()
	{
		mPlayer = new Player();
	}
	void Play1()
	{
		mPlayer->Play1();
	}

	void Play2()
	{
		cout << "û��Ȩ��" << endl;
	}

	void Play3()
	{
		cout << "û��Ȩ��" << endl;
	}
private:
	Play* mPlayer;
};

/*����VIP1���*/
class ProxyPlayerVip1 :public Play
{
public:
	ProxyPlayerVip1()
	{
		mPlayer = new Player();
	}
	void Play1()
	{
		mPlayer->Play1();
	}

	void Play2()
	{
		mPlayer->Play2();
	}

	void Play3()
	{
		cout << "û��Ȩ��" << endl;
	}
private:
	Play* mPlayer;
};

//����Ϊ�����ż�***************
//template<typename ReturnValue, typename T, typename T2>
//class IMutiUser
//{
//public:
//	virtual	ReturnValue(T)(...) = 0;
//	virtual ReturnValue GetReturnType()const = 0;
//};
//
//
///*********************************************************************/
//template<typename ReturnValue, typename T, typename T2>
//class IMutiProxy :public IMutiUser<ReturnValue, T, T2>
//{
//protected:
//	T2*  mMImpl;
//public:
//	virtual ReturnValue(T)(...) override;
//	virtual ReturnValue GetReturnType()const override;
//};
//template<typename ReturnValue, typename T, typename T2>
//ReturnValue IMutiProxy<ReturnValue, T, T2>::T(...)
//{
//	mMImpl = new T2();
//	if (mMImpl != nullptr)
//	{
//		std::cout << "Show Something of IMutiProxy!" << std::endl;
//		mMImpl->T();
//	}
//	ReturnValue temp = NULL;
//	return temp;
//}
//
//
//template<typename ReturnValue, typename T, typename T2>
//ReturnValue IMutiProxy<ReturnValue, T, T2>::GetReturnType()const
//{
//	ReturnValue temp = NULL;
//	return temp;
//}
//
//
///*********************************************************************/
//template<typename ReturnValue, typename T, typename T2>
//class IMutiImplement :public IMutiUser<ReturnValue, T, T2>
//{
//public:
//	virtual ReturnValue(T)(...) override;
//	virtual ReturnValue GetReturnType() const override;
//};
//
//template<typename ReturnValue, typename T, typename T2>
//ReturnValue IMutiImplement<ReturnValue, T, T2>::T(...)
//{
//	std::cout << "show something!" << std::endl;
//	std::cout << "You could dispose something for custom function ." << std::endl;
//	ReturnValue temp = NULL;
//	return temp;
//}
//
//
//template<typename ReturnValue, typename T, typename T2>
//ReturnValue IMutiImplement<ReturnValue, T, T2>::GetReturnType() const
//{
//	ReturnValue temp = NULL;
//	return temp;
//}
