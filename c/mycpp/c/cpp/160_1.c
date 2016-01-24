#include <stdio.h>

int main(void)
{
	char a[26];
	for(int i=0;i<26;a[i++]='a'+i-1);
	for(int i=0;i<26;printf("%c ",a[i++]));
	return 0;
}
