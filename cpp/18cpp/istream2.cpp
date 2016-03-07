#include <fstream>
#include <iostream>
#include <string>
using namespace std;
void readfile(string& str,ifstream& ifs)
{
	int ch;
	while(ifs.good()){
		ch=ifs.get();
		if(ch==EOF)
			break;
		str+=ch;
	}
}
int main(void)
{
	string str;
	ifstream ifs("src");
	readfile(str,ifs);
	cout<<str;
	return 0;
}
