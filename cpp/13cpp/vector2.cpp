#include <iostream>
#include <vector>
using namespace std;
void printVector(vector<int>& v)
{
	for(auto& i:v)
		cout<<i<<" ";
}
int main(void)
{
	vector<int> vectorOne={1,2,3,5};
	vector<int> vectorTwo;
	//Oops, we forgot to add 4. Insert it in the correct place.
	vectorOne.insert(vectorOne.begin()+3,4);
	//Add elements 6 through 10 to vectorTwo
	for(int i=6;i<=10;i++){
		vectorTwo.push_back(i);
	}
	printVector(vectorOne);
	printVector(vectorTwo);
	//Add all the elements from vectorTwo to the end of vectorOne.
	vectorOne.insert(vectorOne.end(),vectorTwo.begin(),vectorTwo.end());
	printVector(vectorOne);
	//Now erase the numbers 2 through 5 in vectorOne.
	vectorOne.erase(vectorOne.begin()+1,vectorOne.begin()+5);
	printVector(vectorOne);
	//Clear vectorTwo entirely.
	vectorTwo.clear();
	//And add 10 copies of the value 100.
	vectorTwo.insert(vectorTwo.begin(),10,100);
	//Decide we only want 9 elements.
	vectorTwo.pop_back();
	printVector(vectorTwo);
	return 0;
}
