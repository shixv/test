class yuangong{
	public:
		youangong(string name,int age){
			this->name=name;
			this->age=age;
		}
	public:
		string name;
		int age;
};

void createyuangong(vector<yuangongj>& yuangongs)
{
	string seedName="ABCDE";
	for(int i=0;i<5;i++){
		yuangong yuangong1;
		yuangong1.name="yuangong";
		try{
		yuangong1.name+=seedName.at(i);
		}
		catch(...){
			cout<<"abcdezifu jiu wu ge ,ni chuang jian duo yu 5 ge yuna gong"<<endl;
			}
		yuangong1.age=read()%10+20;
		yuangongs.pushback(yuangong1);
	}
}
int main(void)
{
	vector<yuangong> vyuangong;
	createyuangong(vyuangong);




