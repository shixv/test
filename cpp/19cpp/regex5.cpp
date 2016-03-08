#include <regex>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(void)
{
	regex reg(R"([\w]+)");
	while(true){
		cout<<"Enter a string to split (q=quit): ";
		string str;
		if(!getline(cin,str)||str=="q")
			break;
		const sregex_token_iterator end;
		for(sregex_token_iterator iter(str.begin(),str.end(),reg);
				iter!=end;++iter){
			cout<<"\""<<*iter<<"\""<<endl;
		}
	}
	return 0;
}
