#include<iostream>
#include <vector>

using namespace std;

//����

void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

//ȫ���еݹ鷽��
void Perm(std::vector<int>&list, int k, int m)
{
	//list ���������е�����K��ʾ�� ����ڼ�������m��ʾ����ĳ���
	if (k == m)
	{
		//K==m ��ʾ�������һ�����������ٽ��������յ����е�����Ҫ�����
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



