#include <iostream>
#include <list>
using namespace std;
class AbstractBuilding{
	public:
		AbstractBuilding(const string& str){
			quality=str;
		}
		virtual void sale()=0;
		virtual ~AbstractBuilding(){}
		string quality;
};
class BuildingA:public AbstractBuilding{
	public:
		BuildingA():AbstractBuilding("di"){}
		~BuildingA(){}
		void sale(){
			cout<<"didangloupanbeishoumai"<<endl;
		}
};
class BuildingB:public AbstractBuilding{
	public:
		BuildingB():AbstractBuilding("zhong"){}
		~BuildingB(){}
		void sale(){
			cout<<"zhongdangloupanbeishoumai"<<endl;
		}
};
class BuildingC:public AbstractBuilding{
	public:
		BuildingC():AbstractBuilding("gao"){}
		~BuildingC(){}
		void sale(){
			cout<<"gaodangloupanbeishoumai"<<endl;
		}
};
class Mediator{
	public:
		Mediator(){
			AbstractBuilding* building=NULL;
			building=new BuildingA;
			mList.push_back(building);
			building=new BuildingB;
			mList.push_back(building);
			building=new BuildingC;
			mList.push_back(building);
		}
		~Mediator(){
			for(auto& i:mList)
				if(i!=NULL)
					delete i;
		}
		AbstractBuilding* findBuilding(string quality){
			for(auto& i:mList){
				if((*i).quality.compare(quality)==0){
					return i;
				}
			}
			return NULL;
		}
	public:
		list<AbstractBuilding*> mList;				
};
void doBussiness(const string& str){
	Mediator* mediator=new Mediator;
	auto building=mediator->findBuilding(str);
	if(building==NULL){
		cout<<"NULL"<<endl;
		return;
	}
	building->sale();
	delete mediator;
}
int main(void)
{
	doBussiness("di");
	doBussiness("zhong");
	doBussiness("gao");
	return 0;
}
