void test(int a,int b){

}
void test2(int a,char b){

}
using Func=void(*)(int,int);
using Func2=void(*)(int,char);

int main(void)
{
	Func a;
	Func2 b=reinterpret_cast<Func2>(a);
	return 0;
}
