#include "TemplateMethod.h"
#include <iostream>

void TestPaper::TestQuestion1()
{
	cout << "杨过得到玄铁,后来给了郭,炼成倚天剑,请问玄铁可能为() a 球磨矿, b 马口铁 c 高速合金钢, d 碳素纤维" << endl;
	cout << endl;
	cout << "答案是:" << answer1() << endl;
	cout << endl;
}
void TestPaper::TestQuestion2()
{
	cout << "杨过,程英,陆无双铲除了情花,造成了,() a 这种植物不再害人, b 使一种珍惜植物灭绝 c 破坏了生态平衡, d 造成该地区沙漠化" << endl;
	cout << endl;
	cout << "答案是:" << answer2() << endl;
	cout << endl;
}
void TestPaper::TestQuestion3()
{
	cout << "蓝凤凰致使华山师徒,桃谷六仙呕吐不止,如果你是医生,请问你要用什么药() a 阿斯匹林, b 牛黄解毒片 c 氲气, d 牛奶" << endl;
	cout << endl;
	cout << "答案是:" << answer3() << endl;
	cout << endl;
}