#pragma once
#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;
/*在游戏中，通过代理来控制不同的vip玩家*/

/*抽象接口*/
class Play {
public:
	virtual void Play1() = 0;
	virtual void Play2() = 0;
	virtual void Play3() = 0;
};

/*被代理者*/
class Player : public Play {
public:
	void Play1() {
		cout << "普通战役" << endl;
	}
	void Play2() {
		cout << "军团战役" << endl;
	}
	void Play3() {
		cout << "神器" << endl;
	}

};

/*代理VIP0玩家*/
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
		cout << "没有权限" << endl;
	}

	void Play3()
	{
		cout << "没有权限" << endl;
	}
private:
	Play* mPlayer;
};

/*代理VIP1玩家*/
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
		cout << "没有权限" << endl;
	}
private:
	Play* mPlayer;
};

//以下为代码炫技***************
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
