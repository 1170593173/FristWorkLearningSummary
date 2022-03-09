#include <iostream>
#include <regex>

using namespace std;

int main() {
	std::cmatch m;

	std::regex reg("(<.*>.*</.*>)(.*)");
	bool ret= std::regex_match("_<html>value<<//html>",m, reg);
	
	auto ret1 = std::regex_match("<xml>value<uu</jxml>>>abcd", m,reg);
	if (ret)
	{
		std::cout << m.str() << std::endl;
		std::cout << m.length() << std::endl;
		std::cout << m.position() << std::endl;
	}
	
	std::regex reg2("<(.*)>.*</\\1>");
	ret = std::regex_match("<xml>..<xml>value</xml>", m, reg2);
	//assert(ret);

	return 0;
}
