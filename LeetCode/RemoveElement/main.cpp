#include<iostream>
#include <vector>
using namespace std;


int RemoveElement(vector<int>mdata,int target) {
	int fast = 0, slow = 0;
	while (fast<mdata.size())
	{
		if (target == mdata[fast])
		{
			fast++;
		}
		else
		{
			mdata[slow++] = mdata[fast++];
		}
	}
	return slow;
}


int main() {
	vector<int>mdata = { 1,2,3,4,5,4,1,2,4,6,1,1,2 };
	int index=RemoveElement(mdata, 1);
	return 0;
} 