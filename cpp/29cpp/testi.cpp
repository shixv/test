#include <iostream>
using namespace std;
class singleton{
    public:
        static singleton* getInstance(){
            return instance;
        }
    public:
    private:
        singleton(){}
        static singleton* instance;
};
singleton* singleton::instance=new singleton;

int main(void)
{
    singleton* h1=singleton::getInstance();
    singleton* h2=singleton::getInstance();

    if(h1==h2){
        cout<<"1"<<endl;
    }
    else
    {
        cout<<"0"<<endl;
    }
    return 0;
}
