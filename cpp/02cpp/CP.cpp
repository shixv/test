#include <iostream>

using namespace std;

class Point
{
	public:
		double px;
		double py;
};
class ACircle
{
	private:
		double m_x;
		double m_y;
		double m_r;
	public:
		void setACircle(double,double,double);
		bool judge(Point &);
};

void ACircle::setACircle(double x,double y,double r)
{
	m_x=x;
	m_y=y;
	m_r=r;
}

bool ACircle::judge(Point &p)
{
	double dx=p.px-m_x;
	double dy=p.py-m_y;
	if((dx*dx+dy*dy)>m_r*m_r)
		return false;
	return true;
}

int main(void)
{
	ACircle ac;
	Point p;
	p.px=1.4;
	p.py=2.3;
	ac.setACircle(3.0,2.0,5.0);
	cout<<ac.judge(p)<<endl;
	return 0;
}

