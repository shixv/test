#include <fstream>
#include <iostream>
using namespace std;
int main(void)
{
	ofstream fout("test.out");
	if(!fout){
		cerr<<"Error opening test.out for writing"<<endl;
		return 1;
	}
	
	fout<<"12345";

	ios_base::streampos curPos=fout.tellp();
	if(5==curPos){
		cout<<"Test passed: Currently at position 5"<<endl;
	}else{
		cout<<"Test failed: Not at position 5"<<endl;
	}
	
	fout.seekp(2,ios_base::beg);

	fout<<0;
	fout.close();

	ifstream fin("test.out");
	if(!fin){
		cerr<<"Error opening test.out for reading"<<endl;
		return 1;
	}
	
	int testVal;
	fin>>testVal;

	const int expected=12045;
	if(testVal==expected){
		cout<<"Test passed: Value is "<<expected<<endl;
	}else{
		cout<<"Test failed: Value is not "<<expected
			<<" (it was "<<testVal<<")"<<endl;
	}
	return 0;
}
