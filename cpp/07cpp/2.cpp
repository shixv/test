#include <iostream>

using namespace std;

class Hero
{
	private:
		int ad;
		int def;
		int hp;
	public:
		Hero(int a,int d,int h)
		{
			ad=a;
			def=d;
			hp=h;
		}
		int getad(){return ad;}
		int getdef(){return def;}
		int gethp(){return hp;}
		void battle(const Hero &hr)
		{
			hp-=((hr.ad/(100+def))?(hr.ad/(100+def)):1);
		}
};

int main(void)
{
	Hero h1(100,200,1000);
	Hero h2(99,180,900);
	
	while(1)
	{
		if(h1.gethp()<=0)
		{
			cout<<"h1 win!!!!"<<endl;
			return 0;
		}
		if(h2.gethp()<=0)
		{
			cout<<"h2 win!!!!"<<endl;
			return 0;
		}
		h1.battle(h2);
		h2.battle(h1);
	}
	return 0;
}
		
