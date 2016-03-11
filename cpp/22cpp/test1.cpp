#include <iostream>
#include <random>
#include <ctime>
#include <functional>
#include <chrono>
#include <ratio>
#include "binarysearchtree.h"
using namespace std;
using namespace chrono;
int main(void)
{
	BinarySearchTree<int> t;
	mt19937 eng(static_cast<unsigned long>(time(nullptr)));
	uniform_int_distribution<int> dist(1,1000000);
	auto gen=std::bind(dist,eng);
	auto start=high_resolution_clock::now();
	for(int i=0;i<100000;i++){
			t.insert(gen());
	}
	auto end=high_resolution_clock::now();
	cout<<t.depth()<<endl;
	cout<<duration<double,ratio<1>>(end-start).count()<<"s"<<endl;
	return 0;
}
