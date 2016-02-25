#include <iostream>
using namespace std;
typedef struct {
	char firstInitial;
	char middleInitial;
	char lastInitial;
	int employeeNumber;
	int salary;
}EmployeeT;
int main(void)
{
	EmployeeT anEmployee;
	anEmployee.firstInitial='M';
	anEmployee.middleInitial='R';
	anEmployee.lastInitial='G';
	anEmployee.employeeNumber=42;
	anEmployee.salary=80000;
	cout<<"Employee: "<<anEmployee.firstInitial<<anEmployee.middleInitial<<anEmployee.lastInitial<<endl;
	cout<<"Number: "<<anEmployee.employeeNumber<<endl;
	cout<<"Salary: $"<<anEmployee.salary<<endl;
	return 0;
}
