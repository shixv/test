#include <iostream>
#include "kbhit.h"
using namespace std;
int main(void)
{
    char ch=0;
    while(ch!='q'){
        cout<<endl;
        if(kbhit(ch,0.02)){
            cout.width(ch);
            cout<<ch<<endl;
        }
    }
    return 0;
}
