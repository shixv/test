#include <iostream>
#include <cmath>

using namespace std;

class Point
{
public:
	//告诉编译器，Point 类有一个友元函数 PointDistance
	//PointDistance 可以直接访问我的私有成员
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

//写一个全局的方法
//类似这种PointDistance类的外部的函数，可能经常需要访问Point类的成员变量
//如果每次都是调用getter 方法来获取的， 效率低

//友元 破坏了 类的封装特性。
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
