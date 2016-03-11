void refcall(int& t){++t;}
int main(void){
	int* ptr=nullptr;
	refcall(*ptr);
	return 0;
}
