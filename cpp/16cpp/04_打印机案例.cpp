#include<iostream>
#include<string>
using namespace std;
//打印机
class Printer{
	public:
		static Printer* getInstance(){
			return instance;
		}
		void print(string content){
			cnt++;
			cout << "打印内容:" << content <<",打印机使用了" << cnt << "次!" << endl;
		}
	private:
		Printer(){}
		static Printer* instance;
		static int cnt;
};
Printer* Printer::instance = new Printer;
int Printer::cnt = 0;
int main(){
	Printer* user1 = Printer::getInstance();
	Printer* user2 = Printer::getInstance();
	user1->print("CET4");
	user2->print("离职申请!");
	return system("pause");
}
