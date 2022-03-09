#include <iostream>
#include <vector>
#include <string>
using namespace std;

//void f(const int& n) {
//	n += 1; // ����ʧ�ܣ�const��ֵ���ò����޸�ָ�����
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


	//ʹ��move����Ҫ�����Ǽ��ٶ���ʱ�ڴ�ռ�Ŀ������ͷţ�ʵ����ֵ�����ս��������ת��

	//����Ĺ��캯��ʵ����û�й���President�Ķ��󣬻���˵û�����ڴ��п��ٶ���Ŀռ�
	//���ȸ��������ڹ��캯����ʵ�ֵ��ǲ���֮���ֵ�Ĵ��ݣ������һ����ֵ����
	//�����֮����ʹ��vector�е�emplace_backʱ������vector���ƶ����캯����ʵ����һ����ֵת�ƣ�������û��ʵ�ʵ��ڴ�ռ䱻��Ϊ�м�ֵʹ�õģ�������Ч��
	President(std::string p_name, std::string p_country, int p_year)
		: name(std::move(p_name)), country(std::move(p_country)), year(std::move(p_year))
	{
		std::cout << "I am being constructed.\n";
	}

	//ʵ�ֵ��ǿ������캯�������������ֵʱ�����øú�����
	//����ͨ�Ŀ������캯����ʹ��moveҲ���Ա�Ҫʹ����ʱ�ڴ�ռ��ʹ��
	President(const President& other)
		: name(std::move(other.name)), country(std::move(other.country)), year(other.year)
	{
		std::cout << "I am being copy constructed.\n";
	}

	//ʵ��ת�ƹ��캯����������Ϊ��ֵʱ�����øú���
	//ʹ����ֵ����֮��ʹ��move����ص���ֵ����ת�ƣ�����ʱ����ֵ�����Ƴ�����ʱ����ֵ���ֵ��û����
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
	elections.emplace_back("Nelson Mandela", "South Africa", 1994); //û����Ĵ���  

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
