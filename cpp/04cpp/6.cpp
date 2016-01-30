#include <iostream>
#include <cmath>

using namespace std;

class Point
{
public:
	//���߱�������Point ����һ����Ԫ���� PointDistance
	//PointDistance ����ֱ�ӷ����ҵ�˽�г�Ա
	friend double PointDistance(Point &p1, Point &p2);

	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	int getX()
	{
		return this->x;
	}
	int getY()
	{
		return this->y;
	}
	void printPoint()
	{
		cout << "x = " << x << "y =  " << y << endl;
	}


private:

	int x;
	int y;
};

//дһ��ȫ�ֵķ���
//��������PointDistance����ⲿ�ĺ��������ܾ�����Ҫ����Point��ĳ�Ա����
//���ÿ�ζ��ǵ���getter ��������ȡ�ģ� Ч�ʵ�

//��Ԫ �ƻ��� ��ķ�װ���ԡ�
double PointDistance(Point &p1, Point &p2)
{
	//int dd_x = p1.x - p2.x;
	//int dd_x = p1.getX() - p2.getX();

	//int dd_y = p1.getY() - p2.getY();
	int dd_x = p1.x - p2.x;
	int dd_y = p1.y - p2.y;

	return sqrt(dd_x*dd_x + dd_y*dd_y);
}

int main(void)
{
	Point p1(10, 20);
	Point p2(5, 6);

	double dis = PointDistance(p1, p2);

	cout << "dis = " << dis << endl;
	
	return 0;
}
