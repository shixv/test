#include <iostream>
#include "animal.h"
#include "cat.h"
#include "dog.h"

int main(void)
{
	Animal *a=new Cat;
	Animal *b=new Dog;

	a->voice();
	b->voice();
	return 0;
}
