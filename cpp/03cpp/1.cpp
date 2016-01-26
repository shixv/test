#include <iostream>
#include <cmath>

using namespace std;

class Point
{
	private:
		int m_x;
		int m_y;
	public:
		void setXY(int x,int y)
		{
			m_x=x;
			m_y=y;
		}
		double pointDistance(Point &p)
		{
			int d_x=p.m_x-m_x;
			int d_y=p.m_y-m_y;
			double dis=sqrt(d_x*d_x+d_y*d_y);
			return dis;
		}

};
class Circle
{
	private:
		int m_r;
		Point p0;
	public:
		void setR(int r)
		{
			m_r=r;
		}
		void setXY(int x,int y)
		{
			p0.setXY(x,y);
		}
		bool isIntersection(Circle &c)
		{
			int rr=m_r+c.m_r;
			double dis=p0.pointDistance(c.p0);
			if(dis<=rr)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
};
int main(void)
{
	Circle c1;
	Circle c2;
	int r;
	cout<<"please input 1"<<endl;
	cin>>r;
	c1.setR(r);
	cout<<"please input 1"<<endl;
	cin>>r;
	c2.setR(r);
	return 0;
}
