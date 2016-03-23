#include <iostream>
#include <thread>
#include <chrono>

int main(void)
{
    std::cout<<"countdown:\n";
    std::chrono::seconds one_second(1);
    for(int i=10;i>0;--i){
        std::cout<<i<<std::endl;
        std::this_thread::sleep_for(one_second);
    }
    std::cout<<"Lift off!\n";
    return 0;
}
