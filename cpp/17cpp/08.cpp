#include <list>
#include <iostream>
using namespace std;
class AbstractStudent{
	public:
		virtual void Update()=0;
};
class AbstractMonitor{
	virtual void Notify()=0;
	virtual void addStudent()=0;
	virtual void deleteStudent()=0;
};
class CopyHomeworkStudent:public AbstractStudent{
	public:
		virtual void Update(){
			cout<<"buchaozuoyehaohoaxuexi"<<endl;
		}
		CopyHomeworkStudent(){
			cout<<"zhengzaichaozuoye"<<endl;
		}
};
class SleepStudent:public AbstractStudent{
	public:
		SleepStudent(){
			cout<<"zhengzaishuijao"<<endl;
		}
		virtual void Update(){
			cout<<"bushuijiaolemashangqilai"<<endl;
		}
};
class KissStudent:public AbstractStudent{
	public:
	KissStudent(){
		cout<<"memeda"<<endl;
	}
	virtual void Update(){
		cout<<"bumemeda"<<endl;
	}
};
class Monitor:public AbstractMonitor{
	public:
		void addStudent(AbstractStudent* student){
			mList.push_back(student);
		}
		void deleteStudent(AbstractStudent* student){
			mList.remove(student);
		}
		void Notify(){
			for(auto& i:mList)
				i->Update();
		}
	public:
		list<AbstractStudent*> mList;
};
void test01(){
	AbstractStudent* copystudent=new CopyHomeworkStudent;
	AbstractStudent* sleepstudent=new SleepStudent;
	AbstractStudent* kissstudent=new KissStudent;
	Monitor* monitor=new Monitor;
	monitor->addStudent(copystudent);
	monitor->addStudent(sleepstudent);
	monitor->addStudent(kissstudent);
	monitor->deleteStudent(kissstudent);
	cout<<"banzhurenlaile"<<endl;
	monitor->Notify();
}
int main(void)
{
	test01();
	return 0;
}
