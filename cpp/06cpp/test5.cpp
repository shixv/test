#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

void chg_str(string str)
{
	str="ichgit";
}
int main(void)
{
	string s="sarrr";
	chg_str(s);

	printf("%s\n",s.c_str());
	cout<<s<<endl;
	return 0;
}
