#include <iostream>
#include <string>
using namespace std;
string add(const string&,const string&);
int main(void)
{
	cout<<add("123","456")<<endl;
	return 0;
}
string add(const string& str1,const string& str2){
	return to_string(stoi(str1)+stoi(str2));	
}
