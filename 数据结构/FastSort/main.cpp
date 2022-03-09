#include <iostream>
#include <vector>
using namespace std;

/*快速排序*/
int Fast_Sort_Core(vector<int>&data, int left, int right) {
	int key = data[left];
	while (left<right)
	{
		while (left<right&&data[right]>=key)
		{
			right--;
		}
		if (left < right) {
			data[left++] = data[right];
		}
		while (left < right&&data[left] <= key) {
			left++;
		}
		if (left < right) {
			data[right--] = data[left];
		}
	}
	data[right] = key;
	return right;
}

void fast_sort(vector<int>&data, int left, int right) {
	if (left >= right) {
		return;
	}
	int mid = Fast_Sort_Core(data, left, right);
	fast_sort(data, left, mid - 1);
	fast_sort(data, mid + 1, right);
}

/*单链表快速排序*/
struct ListNode
{
	int Val;
	ListNode *Next;
};

void Swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

ListNode* ListSortCore(ListNode*pBegin, ListNode*pEnd) {
	if (pBegin == pEnd || pBegin->Next == pEnd) {
		return pBegin;
	}
	int key = pBegin->Val;
	ListNode*slow = pBegin, *fast = pBegin->Next;
	while (fast !=pEnd)
	{
		if (fast->Val < key) {
			slow = slow->Next;
			Swap(slow->Val, fast->Val);
		}
		fast = fast->Next;
	}
	Swap(slow->Val, pBegin->Val);
	return slow;
}

void fast_sort_List(ListNode*pBegin, ListNode*pEnd) {
	if (pBegin != pEnd) {
		ListNode *midNode = ListSortCore(pBegin, pEnd);
		fast_sort_List(pBegin, midNode);
		fast_sort_List(midNode->Next, pEnd);
	}
}

int main() {
	/*单链表快速排序用例*/
	vector<int>val = { 4,2,3,6,8,1,7 };
	vector<ListNode*>all_node_vec;
	ListNode*node;
	for (int i = 0; i < val.size(); ++i) {
		node = new ListNode;
		node->Val = val[i];
		all_node_vec.push_back(node);
	}
	for (int i = 0; i < all_node_vec.size()-1; ++i) {
		all_node_vec[i]->Next = all_node_vec[i + 1];
	}
	all_node_vec.back()->Next = NULL;
	fast_sort_List(all_node_vec[0], all_node_vec.back()->Next);
	

	/*快速排序用例*/
	vector<int> data;
	int num;
	do
	{
		cin >> num;
		data.push_back(num);
	} while (getchar() != '\n');

	fast_sort(data, 0, data.size()-1);
	for (auto m : data)
		cout << m << " ";
	cout << endl;
	return 0;
}