#include <iostream>
#include <cstdlib>

struct teacher 
{
	int data;
	char name[64];
};
void free_teacher(teacher *&tr)
{
	free(tr);
	tr=NULL;
}
int main(void)
{
	return 0;
}
