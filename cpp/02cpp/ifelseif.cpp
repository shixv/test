#include <iostream>
#include <cstdlib>
#include <ctime>
int main(void)
{
	using namespace std;
	int n;

	srand((unsigned int)time(0));
	int Fave=rand()%100+1;
	cout<<"Enter a number in the range 1-100 to find ";
	cout<<"my favorite number: ";
	do
	{
		cin>>n;
		if(n<Fave)
			cout<<"Too low--guess again: ";
		else if(n>Fave)
			cout<<"Too high--guess again: ";
		else
			cout<<Fave<<" is right!\n";
	}while(n!=Fave);
	return 0;
}
