#include <fstream>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main(int argc,char* argv[])
{
    ifstream ifs(argv[1]);
    char ch;
    char flag='\0';
    stack<char> buf;
    vector<char> symbol{'\n','\t',' ','\'','(',')',',',';','{','}','[',']','*','/','+','-','=','.','#','<','>','&','%','!','~','"','?','|','\\'};
    while(ifs.readsome(&ch,1)==1)
    {
        if(flag){
            while(!buf.empty()){
                cout<<buf.top();
                buf.pop();
            }
            cout<<flag;
            flag='\0';
        }
        for(auto& i:symbol){
            if(ch==i){
                flag=ch;
                break;
            }
        }
        if(flag)continue;
        buf.push(ch);
        continue;
    }
    while(!buf.empty()){
        cout<<buf.top();
        buf.pop();
    }
    cout<<endl;
    return 0;
}
