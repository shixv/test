#include <iostream>
#include <string>
using namespace std;
class Printer{
	public:
		static Printer* getInstance(){
			return instance;
		}
		void print(string content){
			cnt++;
			cout<<"dayin neitong"<<content<<"dayinjishiyongle "<<cnt<<"ci"<<endl;
		}
	private:
		Printer(){}
		static Printer* instance;
		static int cnt;
};
Printer* Printer::instance=new Printer;
int Printer::cnt=0;
int main(void){
	Printer* user1=Printer::getInstance();
	Printer* user2=Printer::getInstance();
	user1->print("CET4");
	user2->print("lizhishenqing");
	return 0;
}
