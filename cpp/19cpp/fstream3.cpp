#include <iostream>
using namespace std;
bool changeNumberForID(const string& inFileName,int inID,const string& inNewNumber)
{
	fstream ioData(inFileName.c_str());
	if(!ioData){
		cerr<<"Error while opening file "<<inFileName<<endl;
		return false'
	}
	while(ioData.good()){
		int id;
		string number;
		ioData>>id;
		if(id==inID){
			ioData.seekp(ioData.tellg());
			ioData<<" "<<inNewNumber;
			break;
		}
		ioData>>number;
	}
	return true;
}
