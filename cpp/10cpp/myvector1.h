#include <iostream>
using namespace std;
//1 Myvector �ܹ���� int��  char�� 
//2 MyVector �ܹ���� Teacher����
template<class T>
class MyVector
{
	//��ȫ�ֺ���operator<<����Ϊ��Ԫ
	friend ostream & operator<<(ostream &os, MyVector<T> & vec)
	{
		for (int i = 0; i < vec.len; i++)
		{
			os << vec[i] << endl;
		}
		return os;
	}
	public:
	MyVector();
	MyVector(int len);
	MyVector(const MyVector &another); //�������캯��
	~MyVector();
	//����=�Ų�����
	MyVector &  operator=(const MyVector &another);
	//����[]
	T& operator[](int index);
	//<<
	private:
	int len;
	T *space;
};
	template<typename T>
MyVector<T>::MyVector()
{
	this->len = 0;
	this->space = NULL;
}
	template<typename T>
MyVector<T>::MyVector(int len)
{
	this->len = len;
	this->space = new T[len]; //�ڶ��Ͽ����� len��Ԫ��T�� ����������׵�ַ��space
}
	template<typename T>
MyVector<T>::MyVector(const MyVector &another)
{
	this->len = another.len;
	//deep copy
	this->space = new T[another.len];
	for (int i = 0; i < this->len; i++) {
		this->space[i] = another.space[i];
	}
}
	template<class T>
MyVector<T>&  MyVector<T>::operator=(const MyVector &another)
{
	if (this == &another) {
		return *this;
	}
	if (this->space != NULL) {
		//�����ڵ���=֮ǰ�������Ѿ�������һ���Ŀռ� ����Ҫ�ͷŵ�
		delete[] this->space;
		this->space = NULL;
		this->len = 0;
	}
	//deep copy
	this->len = another.len;
	this->space = new T[this->len];
	for (int i = 0; i < this->len; i++) {
		this->space[i] = another.space[i];
	}
	return *this;
}
	template <class T>
MyVector<T>::~MyVector()
{
	if (this->space != NULL) {
		delete[] this->space;
		this->space = NULL;
		this->len = 0;
	}
}
	template <class T>
T& MyVector<T>::operator[](int index)
{
	return this->space[index];
}

class Teacher
{
	private:
		int  id;
		char *name;
	public:
		Teacher();
		Teacher(int id,char *name);
		Teacher(const Teacher &another);
		~Teacher();

	Teacher &operator=(const Teacher &another);
		friend ostream &operator<<(ostream &os,const Teacher &t);
};
Teacher::Teacher()
{
	this->id=0;
	this->name=NULL;
}
Teacher::Teacher(int id,char *name)
{
	this->id=id;
	this->name=new Teacher[strlen(name)];
	strncpy(this->name,name,strlen(name)]);
}
Teacher::Teacher(const Teacher &another)
{
	this->len=another.len;
	this->name=new char[strlen(another.name)];
	strncpy(this->name,another.name,strlen(another.name));
}
Teacher::~Teacher()
{
	if(this->name!=NULL)
		delete[] name;
	id=0;
	name=NULL;
}
