#include<iostream>
#include <vector>

using namespace std;

//交换

void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

//全排列递归方法
void Perm(std::vector<int>&list, int k, int m)
{
	//list 数组存放排列的数，K表示层 代表第几个数，m表示数组的长度
	if (k == m)
	{
		//K==m 表示到达最后一个数，不能再交换，最终的排列的数需要输出；
		for (int i = 0; i <= m; i++)
			cout << list[i];
		cout << endl;
	}
	else {
		for (int i = k; i <= m; i++)
		{
			swap(list[i], list[k]);
			Perm(list, k + 1, m);
			swap(list[i], list[k]);
		}
	}
}




//void m_swap(int&a, int &b) {
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//
//void test(vector<int>&list, int k, int l) {
//	if (k == l - 1) {
//		for (int i = 0; i < list.size(); ++i)
//		{
//			cout << list[i];
//		}
//		cout << endl;
//	}
//	else
//	{
//		for (int i = k; i < l; ++i)
//		{
//			m_swap(list[i], list[k]);
//			test(list, k + 1, l);
//			m_swap(list[i], list[k]);
//		}
//	}
//}

int main(void)
{
	vector<int>a = { 1,2,3 };
	int m = 2;
	Perm(a, 0, 2);
	//test(a, 0, a.size());
	/*
	? 123

	  ? 132

		? 213

		  ? 231

			? 321

			  ? 312

				*/
}



