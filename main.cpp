#include <iostream>
#include <map>

int main(void)
{
	std::map<std::string, std::string> mmp;
	mmp["0"] = "1";
	mmp["3"] = "3";
	mmp["2"] = "2";
	std::string key, value;
	for (std::map<std::string, std::string>::iterator it=mmp.begin(); it != mmp.end(); it++)
	{
		key = (*it).first;
		value = (*it).second;
		std::cout << key << ":" << value << std::endl;
	}
	return 0;
}
