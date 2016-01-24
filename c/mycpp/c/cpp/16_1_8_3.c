#include <stdio.h>

typedef unsigned int Index;
Index Hash(const char *Key,int TableSize)
{
	Index HashVal=0;
	while(*Key!='\0')
		HashVal+=*key++;
	return HashVal%TableSize;
}
