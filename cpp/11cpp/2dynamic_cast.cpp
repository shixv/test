#include <iostream>
using namespace std;
//����Ķ�����
class Animal
{
	public:
		virtual void cry() = 0;
		virtual void doWork() = 0;
};
class Cat : public Animal
{
	public:
		virtual void cry() {
			cout << "����~~~~" << endl;
		}
		virtual void doWork()
		{
			cout << "ץ����" << endl;
		}
};
class Dog :public Animal
{
	public:
		virtual void cry() {
			cout << "����~~" << endl;
		}
		virtual void doWork()
		{
			cout << "����" << endl;
		}
};
int main(void)
{
	Animal *animal = NULL;
	animal = new Dog;
	animal->cry();
	animal->doWork();
	cout << " -----" << endl;
	Dog * dog = NULL;
	dog = dynamic_cast<Dog*>(animal); //dynamic_cast�ǽ�����ָ��ת��������ָ��
	if (dog != NULL) {
		cout << "ת���ɹ�" << endl;
		dog->cry();
		dog->doWork();
	}
	else {
		cout << "ת��ʧ��" << endl;
	}
	Cat *cat = NULL;
	//��ͨ��dynamic_cast ��animalת����һ��catָ��
	cat = dynamic_cast<Cat*>(animal); //ͨ����animalָ��ת����Catָ��
	//���Խ�һֻ��ת����һֻè
	if (cat != NULL) {
		cout << "ת���ɹ�" << endl;
		cat->cry();
		cat->doWork();
	}
	else {
		cout << "ת��ʧ��" << endl;
	}
	delete animal;
	return 0;
}
