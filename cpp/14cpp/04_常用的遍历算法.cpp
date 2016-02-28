#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//for_each
struct MyPrint{
	void operator()(int v){
		cout << v << " ";
	}
};
//通过迭代器修改元素的值
struct ChangeValue{
	void operator()(int& v){
		v = v + 100;
	}
};
void test01(){
	/*
		template<class _InIt,
		class _Fn1> inline
		void _For_each(_InIt _First, _InIt _Last, _Fn1& _Func)
		{	// perform function for each element
		for (; _First != _Last; ++_First)
		_Func(*_First);
		}
		*/
	vector<int> v;
	for (int i = 0; i < 10;i++){
		v.push_back(i + 1);
	}
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
	//修改元素的值
	for_each(v.begin(), v.end(), ChangeValue());
	//遍历打印
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
	//返回值
}
//transform算法 搬运 将一个容器中的数据元素搬运到另一个容器中
struct MyPlus{
	int operator()(const int& v){
		return v + 100;
	}
};
void test02(){
	/*
		template<class _InIt,
		class _OutIt,
		class _Fn1> inline
		_OutIt _Transform(_InIt _First, _InIt _Last,
		_OutIt _Dest, _Fn1 _Func)
		{	// transform [_First, _Last) with _Func
		for (; _First != _Last; ++_First, ++_Dest)
	 *_Dest = _Func(*_First);
	 return (_Dest);
	 }
	 */
	vector<int> v;
	for (int i = 0; i < 10; i ++){
		v.push_back(i+1);
	}
	vector<int> dest; //目标容器
	dest.resize(v.size()); //开辟空间
	transform(v.begin(), v.end(), dest.begin(), MyPlus());
	//遍历打印
	for_each(dest.begin(), dest.end(), MyPrint());
}
struct MyPlus03{
	int operator()(int v1,int v2){
		return v1 + v2;
	}
};
void test03(){
	/*
		template<class _InIt1,
		class _InIt2,
		class _OutIt,
		class _Fn2> inline
		_OutIt _Transform(_InIt1 _First1, _InIt1 _Last1,
		_InIt2 _First2, _OutIt _Dest, _Fn2 _Func)
		{	// transform [_First1, _Last1) and [_First2, ...) with _Func
		for (; _First1 != _Last1; ++_First1, ++_First2, ++_Dest)
	 *_Dest = _Func(*_First1, *_First2);
	 return (_Dest);
	 }
	 */
	vector<int> v1,v2;
	vector<int> dest; //目标容器
	for (int i = 0; i < 10; i++){
		v1.push_back(i + 1);
		v2.push_back(i+10);
	}
	dest.resize(v1.size());
	//打印v1 v2
	for_each(v1.begin(), v1.end(), MyPrint());
	cout << endl;
	for_each(v2.begin(), v2.end(), MyPrint());
	cout << endl;
	transform(v1.begin(), v1.end(), v2.begin(), dest.begin(), MyPlus03());
	//打印目标容器
	for_each(dest.begin(), dest.end(), MyPrint());
	cout << endl;
}
int main(){
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;
}
