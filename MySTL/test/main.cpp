#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

struct ListNode
{
	ListNode * next;
	int value;
	ListNode(int val) :value(val), next(nullptr) {};
};

//vector<int> twoSum(vector<int>& nums, int target) {
//	std::unordered_map <int, int> map;
//	for (int i = 0; i < nums.size(); i++) {
//		auto iter = map.find(target - nums[i]);
//		if (iter != map.end()) {
//			return{ iter->second, i };
//
//		}
//		map.insert(nums[i], i);
//	}
//	return{};
//}

/*ȥ�����ַ����Ķ���ո�*/
void  removeSpace(string &m_str) {
	//����ָ��
	int slow = 0,fast=0;
	//int i = 0;
	while (m_str[fast]==' '&&fast<m_str.size())
	{
		fast++;
	}
	bool isfristSapce = true;
	while (fast<m_str.size())
	{
		if (m_str[fast]!=' ')
		{
			m_str[slow] = m_str[fast];
			slow++;
			isfristSapce = true;
		}
		else
		{	
			if (isfristSapce)
			{
				isfristSapce = false;
				m_str[slow] = m_str[fast];
				slow++;
			}
		}
		fast++;
	}
	/*ȥ�����һ���ո�*/
	m_str.resize(--slow);
	//return m_str;
}


int main(){
	ListNode*pRoot = new ListNode(0);
	ListNode*pNode = new ListNode(1);
	pRoot->next = pNode;

	int *a = new int(1);
	int *b = a;
	*a = 22;
	cout << *b << endl;

	//string *h = new string("sssssss");
	string test = "   222 3 44   56jj kw    ";
	removeSpace(test);

	getchar();
	return 0;
}