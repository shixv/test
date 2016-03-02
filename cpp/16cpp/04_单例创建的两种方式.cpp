#include<iostream>
using namespace std;
//����ʽ
class Singleton_lazy{
public:
	static Singleton_lazy* getInstance(){
		if (instance == NULL){
			instance = new Singleton_lazy;
		}
		return instance;
	}
private:
	Singleton_lazy(){}
	static Singleton_lazy* instance;
};
Singleton_lazy* Singleton_lazy::instance = NULL;
//����ʽ
class Singleton_hungry{
public:
	static Singleton_hungry* getInstance(){
		return instance;
	}
public:
private:
	Singleton_hungry(){} //˽�л����캯��
	static Singleton_hungry* instance;
};
Singleton_hungry* Singleton_hungry::instance = new Singleton_hungry;
void test01(){
	//����ʽ
	Singleton_lazy* lazy1 = Singleton_lazy::getInstance();
	Singleton_lazy* lazy2 = Singleton_lazy::getInstance();
	if (lazy1 == lazy2){
		cout << "��ͬ" << endl;
	}
	else{
		cout << "����ͬ!" << endl;
	}
	//����ʽ
	Singleton_hungry* hungry1 = Singleton_hungry::getInstance();
	Singleton_hungry* hungry2 = Singleton_hungry::getInstance();
	if (hungry1 == hungry2){
		cout << "��ͬ" << endl;
	}
	else{
		cout << "����ͬ!" << endl;
	}
}
int main(){
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
