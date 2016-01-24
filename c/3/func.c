//void (*func)(int a)
//{
//}

//void (*)(int ) 
void func(int a) {
	printf("%d\n", a);
	return;
}

void my_func(void (*fp)(int), int a) 
{
	fp(a);
}


void (*func(int a))(int b)
{

}

typedef void(*p_t)(int);
p_t func(int a);

int main(void)
{
	my_func(func, 10);
}
