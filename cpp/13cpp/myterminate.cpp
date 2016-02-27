#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;
void readIntegerFile(const string& filename,vector<int>& dest)
	throw(invalid_argument,runtime_error)
{
	throw 5;
}
void myTerminate()
{
	cout<<"Uncaught exception!"<<endl;
	exit(1);
}
int main(void)
{
	vector<int> myInts;
	const string fileName="IntegerFile.txt";
	set_terminate(myTerminate);
	readIntegerFile(fileName,myInts);
	for(size_t i=0;i<myInts.size();i++){
		cout<<myInts[i]<<" ";
	}
	cout<<endl;
	return 0;
}
