#include <iostream>
using namespace std;
class eSize
{
	public:
		eSize(int len){
			this->len=len;
		}
		virtual void printError()=0;
	protected:
		int len;
};
class eNagtive:public eSize
{
	public:
		eNagtive(int len):eSize(len)
	{
	}
		virtual void printError()
		{
			cout<<"eNagtive error: len="<<this->len<<endl;
		}
};
class eZero:public eSize
{
	public:
		eZero(int len):eSize(len){}
		virtual void printError()
		{
			cout<<"eZero error: len="<<this->len<<endl;
		}
};
class eTooBig:public eSize
{
	public:
		eTooBig(int len):eSize(len){}
		virtual void printError()
		{
			cout<<"eTooBig error: len="<<this->len<<endl;
		}
};
class eTooSmall:public eSize
{
	public:
		eTooSmall(int len):eSize(len){}
		virtual void printError()
		{
			cout<<"eTooSmall error: len="<<this->len<<endl;
		}
};
class MyArray
{
	public:
		MyArray(int len)
		{
			if(len<0){
				throw eNagtive(len);
			}
			else if(len==0){
				throw eZero(len);
			}
			else if(len>1000){
				throw eTooBig(len);
			}
			else if(len<10){
				throw eTooSmall(len);
			}
			this->len=0;
			this->space=new int[len];
		}
		int &operator[](int index)
		{
			return this->space[index];
		}
		~MyArray()
		{
			if(this->space!=NULL){
				delete[]this->space;
				this->space=NULL;
				this->len=0;
			}
		}
	private:
		int len;
		int *space;
};
int main(void)
{
	try{
		MyArray array(10001);
	}
	catch(eSize &e)
	{
		e.printError();
	}
	return 0;
}

