#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main(void)
{
	regex reg(R"(^(\d{4})/(0?[1-9]|1[0-2])/(0?[1-9]|[1-2][0-9]|3[0-1])$)");
	while(true){
		cout<<"Enter a date (year/month/day) (q=quit): ";
		string str;
		if(!getline(cin,str)||str=="q")
			break;
		vector<int> vec={0,1,2,3,4};
		const sregex_token_iterator end;
		for(sregex_token_iterator iter(str.begin(),str.end(),reg,vec);iter!=end;++iter){
			cout<<"\""<<*iter<<"\""<<endl;
		}
	}
	return 0;
}
