#include <iostream>

using namespace std;

class bed
{
  public:
	void sleep();
};

class sofa
{
  public:
	void sit();
};

void bed::sleep()
{
  cout<<"sleep in bed"<<endl;
}

void sofa::sit()
{
  cout<<"sit in sofa"<<endl;
}

class sofabed:public sofa,public bed
{
  public:
  void dosomething(void)
  {
	sleep();
	sit();
  }
};
int main(void)
{
  bed b;
  sofa s;
  sofabed sb;
  sb.dosomething();
  return 0;
}
