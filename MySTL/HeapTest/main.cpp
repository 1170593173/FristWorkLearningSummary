#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

//����һ����ȫ��������������ǿ������������洢���нڵ㡣

int main() {
	vector<int>data{ 9, 6, 2, 4, 7, 0, 1, 8, 3, 5 };
	//����һ���ѣ�Ĭ���Ǵ󶥶�
	//make_heap(data.begin(),data.end());
	/*9 8 2 6 7 0 1 4 3 5*/
	make_heap(data.begin(),data.end(),less<int>());
	for (auto i : data)
	{
		cout << i << " ";
	};

	//�Ƴ��Ѷ����ݣ��ŵ���������ĩβ
	/*8 2 6 7 0 1 4 3 5 9*/
	//pop_heap(data.begin(), data.end());

	/*9 8 2 6 7 0 1 4 3 5 11*/
	data.push_back(11);
	/*���Ԫ�ص��ѣ�������Ҫ�������������Ԫ�أ����������Ԫ��ʱ���е�Ԫ�ر����������*/
	/*11 9 8 2 6 7 0 1 4 3 5*/
	push_heap(data.begin(), data.end());

	//�Զ�����
	/*0 1 2 3 4 5 6 7 8 9 11*/
	sort_heap(data.begin(), data.end());
	for (auto i : data)
	{
		cout << i << " ";
	};
	//����һ��С����
	make_heap(data.begin(), data.end(), cmp);

	return 0;
}