#include <iostream>
#include <fstream>
#include <regex>
#include <string>
using namespace std;
int main(void)
{
	regex r(R"(^$)");
	ifstream ifs("txt");
	string str;
	while(ifs>>str);
	ofstream ofs("dec");

	ofs<<regex_replace(str,r,"");
	
	return 0;
}	
