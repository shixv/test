#include <iostream>
#include <thread>
#include <unistd.h>
using namespace std;

void counter(int id,int numIterations)
{
    for(int i=0;i<numIterations;++i){
        cout<<"Counter "<<id<<" has value ";
        cout<<i<<endl;
        sleep(1);
    }
}

int main(void)
{
    cout.sync_with_stdio(true);
    thread t1(counter,1,10);
    thread t2(counter,2,10);
    t2.join();
    t1.join();
    return 0;
}
