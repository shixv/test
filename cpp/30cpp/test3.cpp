#include "kbhit.h"
#include <iostream>
using namespace std;
int main(void)
{
	int ch;
	while(ch!='q'){
		cout<<endl;
		if(kbhit(ch,1)){
			cout<<(char)ch<<endl;
		}
	}
	return 0;
}
