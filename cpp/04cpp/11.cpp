#include <cstring>
#include <iostream>

using namespace std;

class Student
{
	public:
		Student()
		{
			this->id=0;
			this->name=NULL;
		}
		Student(int id,const char *name)
		{
			this->id=id;

			int len=strlen(name);
			this->name=new char[len+1];
			strcpy(this->name,name);
		}
		Student(const Student &another)
		{
			this->id=another.id;
			int len=strlen(another.name);
			this->name=new char[len+1];
			strcpy(this->name,another.name);
		}

		void printS()
		{
			cout<<"id= "<<this->id<<", name= "<<this->name<<endl;
		}

		Student &operator=(const Student &another)
		{
			if(this->name!=NULL)
			{
				delete[] this->name;
				this->name=NULL;
				this->id=0;
			}
			this->id=another.id;
			int len=strlen(another.name);
			this->name=new char[len+1];
			strcpy(this->name,another.name);
			return *this;
		}
		~Student()
		{
			if(this->name!=NULL)
			{
				delete[] this->name;
				this->name=NULL;
				this->id=0;
			}
		}
	private:
		int id;
		char *name;
};

int main(void)
{
	Student s1(1,"zhang3");
	Student s2=s1;
	Student s3;

	s1.printS();
	s2.printS();

	cout<<"-----"<<endl;

	s3=s2;
	s3.printS();

	Student s4(2,"li4");

	s3=s4;

	s3.printS();

	return 0;
}
