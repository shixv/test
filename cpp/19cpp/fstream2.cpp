#include <fstream>
#include <iostream>
using namespace std;
int main(void)
{
	ifstream inFile("output.txt");
	ofstream outFile("output.txt");

	inFile.tie(&outFile);

	outFile<<"Hello there!";

	outFile.flush();
//	inFile.flush();
	string nextToken;
	inFile>>nextToken;
	cout<<nextToken<<endl;

	return 0;
}
