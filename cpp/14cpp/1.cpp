#include<iostream>
using namespace std;
#include<vector>
#include<string>
class Player{
	public:
		Player(char* name,int age){
			int len = strlen(name) + 1;
			this->name = new char[len];
			strcpy(this->name, name);
			this->age = age;
		}
		//增加拷贝构造
		//增加拷贝构造layer(const Player& p){
		//Playerint len = strlen(p.name) + 1;
		//namethis->name = new char[len];
		//lenstrcpy(this->name, p.name);
		//
		//namethis->age = p.age;
		//age}
		//age//重载=号
		//重载layer& operator=(const Player& p){
		//Playerint len = strlen(p.name) + 1;
		//namethis->name = new char[len];
		//lenstrcpy(this->name, p.name);
		//namethis->age = p.age;
		//agereturn *this;
		//this}
		//
		//
		//this~Player(){
		//Playerif (this->name != NULL){
		//namedelete[] this->name;
		//name}
		//name}
		//
		//public:
		//publicchar* name;
		//nameint age;
		//};
		//
		//void test01(){
		//
		//test01Player p("aaa", 10);
		//
		//10vector<Player> v;
		//Playerv.push_back(p);
		//
		//}
		//
		//
		//int main(){
		//
		//maintest01();
		//
		//
		//maintest01system("pause");
		//pausereturn 0;
		//}
