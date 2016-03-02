#include <iostream>
#include <string>
using namespace std;

class Goods{
	public:
		Goods(string name,bool isreal){
			this->name=name;
			this->isReal=isreal;
		}
	public:
		string name;
		bool isReal;
};
class AbstractShopping{
	public:
		virtual void buyGoods(Goods* goods)=0;
};
class USAShopping:public AbstractShopping{
	public:
		virtual void buyGoods(Goods* goods){
			if(goods->isReal){
			cout<<"zaimeiguogoumai"<<goods->name<<endl;
			cout<<"tonguoanjian,jiangshangpindaishui zuguo"<<endl;
			}
			else{
				cout<<"ziameiguo jiahuo"<<goods->name<<endl;
			}
		}
};
class JAPShopping:public AbstractShopping{
	public:
		virtual void buyGoods(Goods* goods){
			if(goods->isReal){
			cout<<"zaimeiguogoumai"<<goods->name<<endl;
			cout<<"tonguoanjian,jiangshangpindaishui zuguo"<<endl;
			}
			else{
				cout<<"ziameiguo jiahuo"<<goods->name<<endl;
			}
		}
};
void test01(void){
	Goods* goods=new Goods("qiche",true);
	AbstractShopping* usa=new USAShopping;
	usa->buyGoods(goods);
}
class OverseasProxy:public AbstractShopping{
	public:
		OverseasProxy(AbstractShopping* where){
			whereShopping=where;
		}
		virtual void buyGoods(Goods* goods){
			if(goods->isReal){
				whereShopping->buyGoods(goods);
				cout<<"tongguo"<<endl;
			}
			else{
				cout<<"jiahuofanhqo"<<endl;
			}
		}
	public:
		AbstractShopping* whereShopping;
};
				
void test02(){
	Goods* goods=new Goods("matonggai",false);
	OverseasProxy* proxy=new OverseasProxy(new JAPShopping);
	proxy->buyGoods(goods);
}
int main(void)
{
	test01();
	test02();
	return 0;
}
