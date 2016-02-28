#include <numeric>
#include <vector>
#include <cmath>
using namespace std;
int product(int num1,int num2)
{
	return num1*num2;
}
double geometricMean(const vector<int>& nums)
{
	double mult=accumulate(nums.begin(),nums.end(),1,product);
	return pow(mult,1.0/nums.size());
}
double geometricMeanLambda(const vector<int>& nums)
{
	double mult=accumulate(nums.begin(),nums.end(),1,
			[](int num1,int num2){return num1*num2;});
	return pow(mult,1.0/nums.size());
}
