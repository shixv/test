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
			cout << "˵���Ļ���ͬѧ,ֹͣ˵����ר��ѧϰ" << endl;
		}
};
class CopyHomeWorkdStudent : public AbstractObserve
{
	public:
		virtual void Update()
		{
			cout << "ֹͣ����ҵ��ר���Լ�д��ҵ." << endl;
		}
};
class PlayTelephoneStudent : public AbstractObserve
{
	public:
		virtual void Update()
		{
			cout << "ֹͣ���ֻ���ר�Ŀ���." << endl;
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
	cout << "�����������... ��ʦ����... ��֪ͨ��Щѧ��..." << endl;
	monitor->Notify();
	cout << "ƽ����˵���Ļ������ͬѧ�Ͱ೤��ϵ���ã��೤����֪ͨ��" << endl;
	monitor->deleteObserver(a1);
	cout << "��ʦ������... �೤֪ͨ�����˵�����β�֪ͨ˵���Ļ����Ǹ�ͬѧ" << endl;
	monitor->Notify();
	//�ͷ���Դ
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
