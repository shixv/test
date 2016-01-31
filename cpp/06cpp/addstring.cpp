#include <iostream>

using namespace std;

class Str
{
	private:
		char *str;
		int n;
	public:
		Str()
		{
			str=NULL;
			n=0;
		}
		Str(const char *s)
		{
			if(s==NULL)
			{
				str==NULL;
				n=0;
				return;
			}
			str=new char[strlen(s)];
			strncpy(str,s,strlen(s));
			n=atoi(s);
		}
		Str &operator=(Str &another)
		{
			
		}
