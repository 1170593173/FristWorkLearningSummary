#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

//堆是一种完全二叉树，因此我们可以用数组来存储所有节点。

int main() {
	vector<int>data{ 9, 6, 2, 4, 7, 0, 1, 8, 3, 5 };
	//创建一个堆，默认是大顶堆
	//make_heap(data.begin(),data.end());
	/*9 8 2 6 7 0 1 4 3 5*/
	make_heap(data.begin(),data.end(),less<int>());
	for (auto i : data)
	{
		cout << i << " ";
	};

	//推出堆顶数据，放到容器的最末尾
	/*8 2 6 7 0 1 4 3 5 9*/
	//pop_heap(data.begin(), data.end());

	/*9 8 2 6 7 0 1 4 3 5 11*/
	data.push_back(11);
	/*添加元素到堆，首先需要先往容器中添加元素，并且在添加元素时堆中的元素必须满足堆序*/
	/*11 9 8 2 6 7 0 1 4 3 5*/
	push_heap(data.begin(), data.end());

	//对堆排序
	/*0 1 2 3 4 5 6 7 8 9 11*/
	sort_heap(data.begin(), data.end());
	for (auto i : data)
	{
		cout << i << " ";
	};
	//创建一个小顶堆
	make_heap(data.begin(), data.end(), cmp);

	return 0;
}