#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 分别处理如下四种情况
// 目标值在数组所有元素之前  [0, -1]
// 目标值等于数组中某一个元素  return middle;
// 目标值插入数组中的位置 [left, right]，return  right + 1
// 目标值在数组所有元素之后的情况 [left, right]， return right + 1
int myTest(vector<int>&testData,int target) {
	int mleft = 0, mright = testData.size() - 1;
	while (mleft<=mright)
	{
		int middle = mright - (mright - mleft) / 2;

		if (target<testData[middle])
		{
			mright = middle - 1;
		}
		else if (target>testData[middle])
		{
			mleft = middle + 1;
		}else
		{
			return middle;
		}
	}
	return -1;
}

int main() {
	//vector<int>mdata = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	vector<int>mdata = {  };
	int index=myTest(mdata, 11);

	return 0;
}
