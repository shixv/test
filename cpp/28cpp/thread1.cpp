#include <iostream>
#include <vector>
#include <thread>
#include <functional>
#include <unistd.h>
void func(int& counter)
{
    for(int i=0;i<10;i++){
        ++counter;
        sleep(1);
    }
}
int main(void)
{
    int counter=0;
    std::vector<std::thread> threads;
    for(int i=0;i<2;++i){
        threads.push_back(std::thread(func,std::ref(counter)));
    }
    for(auto& t:threads){
        t.join();
    }
    std::cout<<"Result = "<<counter<<std::endl;
    return 0;
}
