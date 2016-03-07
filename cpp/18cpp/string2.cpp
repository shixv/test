#include <iostream>
#include <ios>
#include <iomanip>
using namespace std;
void rawWrite(const char* data,int dataSize)
{
	cout.write(data,dataSize);
}
void rawPutChar(const char* data,int charIndex)
{
	cout.put(data[charIndex]);
}
int main(void)
{
//	rawWrite("\n\nfuck \t you!!",10);
//	rawPutChar("he\nheda\t",5);
	if(cout.good()){
		cout<<"All good"<<endl;
	}
	cout.flush();
	if(cout.fail()){
		cerr<<"Unable to flush to standard out"<<endl;
	}
	cout.exceptions(ios::failbit|ios::badbit|ios::eofbit);
	try{
		cout<<"Hello World."<<endl;
		throw (ios_base::failure("dsjf"));
	}catch(const ios_base::failure& ex){
		cerr<<"Caught exception: "<<ex.what()
			<<", error code = "<<ex.code()<<endl;
	}
	cout<<0x123<<hex<<endl;
	cout<<setw(16)<<1.00<<endl;
	cout<<put_money(1)<<1234<<endl;
	cout<<boolalpha<<true<<endl;
	return 0;
}
