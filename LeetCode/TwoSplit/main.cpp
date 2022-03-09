#include <iostream>
#include <string>
#include <vector>

using namespace std;

// �ֱ��������������
// Ŀ��ֵ����������Ԫ��֮ǰ  [0, -1]
// Ŀ��ֵ����������ĳһ��Ԫ��  return middle;
// Ŀ��ֵ���������е�λ�� [left, right]��return  right + 1
// Ŀ��ֵ����������Ԫ��֮������ [left, right]�� return right + 1
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
