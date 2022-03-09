#include <iostream>
#include <vector>
#include <string>
using namespace std;

//void f(const int& n) {
//	n += 1; // 编译失败，const左值引用不能修改指向变量
//}

void f2(int && n) {
	n += 1; // ok
}



class President
{
public:
	std::string name;
	std::string country;
	int year;


	//使用move的主要作用是减少对临时内存空间的开辟与释放，实现右值到最终结果的完美转发

	//这里的构造函数实际上没有构造President的对象，或者说没有在内存中开辟对象的空间
	//首先各个参数在构造函数中实现的是参数之间的值的传递，构造出一个右值对象，
	//构造出之后，在使用vector中的emplace_back时，调用vector的移动构造函数又实现了一次右值转移，最终是没有实际的内存空间被作为中间值使用的，提升了效率
	President(std::string p_name, std::string p_country, int p_year)
		: name(std::move(p_name)), country(std::move(p_country)), year(std::move(p_year))
	{
		std::cout << "I am being constructed.\n";
	}

	//实现的是拷贝构造函数，当入参数左值时，调用该函数；
	//在普通的拷贝构造函数中使用move也可以必要使用零时内存空间的使用
	President(const President& other)
		: name(std::move(other.name)), country(std::move(other.country)), year(other.year)
	{
		std::cout << "I am being copy constructed.\n";
	}

	//实现转移构造函数，当参数为右值时，调用该函数
	//使用右值传入之后，使用move对相关的右值进行转移，对零时的右值进行移除，此时的右值里的值就没有了
	President(President&& other)
		: name(std::move(other.name)), country(std::move(other.country)), year(other.year)
	{
		std::cout << "I am being moved.\n";
	}
	President& operator=(const President& other);
};

int main()
{
	std::vector<President> elections;
	std::cout << "emplace_back:\n";
	elections.emplace_back("Nelson Mandela", "South Africa", 1994); //没有类的创建  

	std::vector<President> reElections;
	std::cout << "\npush_back:\n";
	reElections.push_back(President("Franklin Delano Roosevelt", "the USA", 1936));

	President jj("Franklin Delano Roosevelt", "the USA", 1936);
	President kk(jj);
	reElections.push_back(jj);

	std::cout << "\nContents:\n";
	for (President president : elections) {
		std::cout<<president.name << " was elected president of "
			<< president.country << " in " << president.year << ".\n";
	}


	for (President  president : reElections) {
		std::cout << president.name << " was re-elected president of "
			<< president.country << " in " << president.year << ".\n";
	}
	return 0;
}

//int main() {
//
//	string str1 = "abcdefg";
//	vector<string>vec;
//	vec.push_back(str1);
//
//	vec.push_back(std::move(str1));
//
//	//f(5);
//	f2(5);
//	return 0;
//}
