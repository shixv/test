#include <stdbool.h>
bool isPrime(unsigned long n)
{
	unsigned long div;
	bool isP;
	for(div=2lu,isP=true;(div*div)<=n;div++)
		if(n%div==0)isP=false;
	return isP;
}
