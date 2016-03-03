#include<iostream>
#include<list>
using namespace std;
class AbstractObserve
{
	public:
		virtual void Update() = 0;
};
class WhisperStudent : public AbstractObserve
{
	public:
		virtual void Update()
		{
			cout << "说悄悄话的同学,停止说话，专心学习" << endl;
		}
};
class CopyHomeWorkdStudent : public AbstractObserve
{
	public:
		virtual void Update()
		{
			cout << "停止抄作业，专心自己写作业." << endl;
		}
};
class PlayTelephoneStudent : public AbstractObserve
{
	public:
		virtual void Update()
		{
			cout << "停止玩手机，专心看书." << endl;
		}
};
class AbstractInformer
{
	public:
		virtual void addObserver() = 0;
		virtual void deleteObserver() = 0;
		virtual void Notify() = 0;
};
class Monitor : public AbstractInformer
{
	public:
		virtual void addObserver(AbstractObserve* observer)
		{
			plist.push_back(observer);
		}
		virtual void deleteObserver(AbstractObserve* observer)
		{
			plist.remove(observer);
		}
		virtual void Notify()
		{
			for (list<AbstractObserve*>::iterator it = plist.begin(); it != plist.end(); ++it)
			{
				(*it)->Update();
			}
		}
	private:
		list<AbstractObserve*> plist;
};
void test()
{
	AbstractObserve *a1 = new WhisperStudent;
	AbstractObserve *a2 = new CopyHomeWorkdStudent;
	AbstractObserve *a3 = new PlayTelephoneStudent;
	AbstractInformer* monitor = new Monitor;
	monitor->addObserver(a1);
	monitor->addObserver(a2);
	monitor->addObserver(a3);
	cout << "发生特殊情况... 老师来了... 快通知哪些学生..." << endl;
	monitor->Notify();
	cout << "平日里说悄悄话的这个同学和班长关系不好，班长不想通知他" << endl;
	monitor->deleteObserver(a1);
	cout << "老师又来了... 班长通知其他人但是这次不通知说悄悄话的那个同学" << endl;
	monitor->Notify();
	//释放资源
	delete monitor;
	delete a3;
	delete a2;
	delete a1;
}
int main()
{
	test();	
	return 0;
}
