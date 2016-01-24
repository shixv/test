#include <iostream>
int main(void)
{
	using namespace std;
	int quizscores[10]=
	{20,20,20,20,20,18,29,18,20,20};
	cout<<"Doing it right: \n";
	for(int i=0;quizscores[i]==20;i++)
		cout<<"quiz "<<i<<" is a 20\n";
	cout<<"Doing it dangerously wrong: \n";
	for(int i=0;quizscores[i]==20;i++)
		cout<<"quiz "<<i<<" is a 20\n";
	return 0;
}
