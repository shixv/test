#include <iostream>
#include <ctime>

using namespace std;

typedef struct{
	int day;
	int week;
	int month;
}calData;
class Cal
{
	private:
		calData first;	
	public:
		Cal();
		~Cal();
//		Cal(calData& d);
		Cal(const calData& cd);
		Cal(int year);
};
		
int main(void)
{
	struct tm *tm_ptr;
	time_t the_time;
	(void)time(&the_time);
	tm_ptr=gmtime(&the_time);

	cout<<"year: "<<tm_ptr->tm_year+1900<<endl;
	cout<<"dayofyear: "<<tm_ptr->tm_yday+1<<endl;
	cout<<"dayofweek: "<<tm_ptr->tm_wday<<endl;
	cout<<"month: "<<tm_ptr->tm_mon+1<<endl;
	cout<<"dayofmonth: "<<tm_ptr->tm_mday+1<<endl;

	return 0;
}
