#include <iostream>
using namespace std;
//抽象的动物类
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
			cout << "喵喵~~~~" << endl;
		}
		virtual void doWork()
		{
			cout << "抓老鼠" << endl;
		}
};
class Dog :public Animal
{
	public:
		virtual void cry() {
			cout << "汪汪~~" << endl;
		}
		virtual void doWork()
		{
			cout << "看家" << endl;
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
	dog = dynamic_cast<Dog*>(animal); //dynamic_cast是将父类指针转换成子类指针
	if (dog != NULL) {
		cout << "转换成功" << endl;
		dog->cry();
		dog->doWork();
	}
	else {
		cout << "转换失败" << endl;
	}
	Cat *cat = NULL;
	//想通过dynamic_cast 将animal转换成一个cat指针
	cat = dynamic_cast<Cat*>(animal); //通过将animal指针转换成Cat指针
	//尝试将一只狗转换成一只猫
	if (cat != NULL) {
		cout << "转换成功" << endl;
		cat->cry();
		cat->doWork();
	}
	else {
		cout << "转换失败" << endl;
	}
	delete animal;
	return 0;
}
