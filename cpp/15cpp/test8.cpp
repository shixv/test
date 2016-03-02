#include <iostream>
#include <cstdio>
#include <memory>
using namespace std;
void CloseFile(FILE* filePtr)
{
	if(filePtr==nullptr)
		return;
	fclose(filePtr);
	cout<<"File closed."<<endl;
}
int main(void)
{
	shared_ptr<FILE> filePtr(fopen("data.txt","w"),CloseFile);
	if(filePtr==nullptr){
		cerr<<"Error opening file."<<endl;
	}else{
		cout<<"FILE opened."<<endl;
	}
	return 0;
}
