#include <iostream>
#include <stack>
#include <vector>
#include <ctime>
#include <random>
#include <functional>
#include <ratio>
#include <chrono>
#include <algorithm>
#include <memory>
#include <string>
template <class Comparable=int>
class _Swap
{
	private:
		int _count=1;
	public:
		_Swap(int count=0){
			_count=count;
		}
		bool operator()(Comparable* a,int a1,int a2){
			a[a1]^=a[a2];
			a[a2]^=a[a1];
			a[a1]^=a[a2];
			++_count;
			return true;
		}
		void clear(){
			_count=0;
		}
		int count(){
			return _count;
		}
};
_Swap<int> Swap;
	template <typename Comparable>
std::shared_ptr<std::vector<Comparable>> list(int count)
{
	std::mt19937 eng(static_cast<unsigned long>(std::time(nullptr)));
	std::uniform_int_distribution<int> dist(1,count);
	auto gen=std::bind(dist,eng);
	std::shared_ptr<std::vector<Comparable>> vec(new std::vector<Comparable>(count));
	std::generate(vec->begin(),vec->end(),[&]()->Comparable{return Comparable(gen());});
	return vec;
}
	template <typename Comparable=int>
void testsort(void(*a)(std::vector<Comparable>&),int count=10)
{
	if(count<0)count=10;
	auto v=list<Comparable>(count);
	if(count<=1000)for(auto& i:*v)std::cout<<i<<" ";
	auto start=std::chrono::high_resolution_clock::now();
	a(*v);
	auto end=std::chrono::high_resolution_clock::now();
	if(count<=1000){
		std::cout<<std::endl<<"---------"<<std::endl;
		for(auto& i:*v)std::cout<<i<<" ";
		std::cout<<std::endl;
	}
	std::cout<<std::chrono::duration<double,std::milli>(end-start).count()<<" ms"<<std::endl;
	std::cout<<Swap.count()<<std::endl;
	Swap.clear();
}
	template <typename Comparable=int>
void testsort(void(*a)(Comparable*,int),int count=10)
{
	if(count<0)count=10;
	auto v=list<Comparable>(count);
	if(count<=1000)for(auto& i:*v)std::cout<<i<<" ";
	auto start=std::chrono::high_resolution_clock::now();
	a(v->data(),count);
	auto end=std::chrono::high_resolution_clock::now();
	if(count<=1000){
		std::cout<<std::endl<<"---------"<<std::endl;
		for(auto& i:*v)std::cout<<i<<" ";
		std::cout<<std::endl;
	}
	std::cout<<std::chrono::duration<double,std::milli>(end-start).count()<<" ms"<<std::endl;
	std::cout<<"Swap count: "<<Swap.count()<<std::endl;
	Swap.clear();

}
class Increament{
	private:
		std::shared_ptr<std::stack<int>> inc;
	public:
		Increament(int len){
			inc=std::make_shared<std::stack<int>>();
			int temp=len/2;
			while(temp>0){
				inc->push(temp);
				temp=temp>>1;
			}
		}
		Increament(int len,std::function<int(int)> a){
			int sum=1;
			int i=1;
			inc=std::make_shared<std::stack<int>>();
			while(sum<len&&sum>0){
				inc->push(sum);
				sum=a(i++);
			}
		}
		Increament(int len,void*,std::function<int(int)> a){
			int sum=1;
			inc=std::make_shared<std::stack<int>>();
			while(sum<len&&sum>0){
				inc->push(sum);
				sum=a(sum);
			}
		}
		int operator()(int& gap){
			if(inc->empty())return 0;
			gap=inc->top(); 
			inc->pop();
			return gap;
		}
};
