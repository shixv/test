#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
int main(void)
{
	double PI = 3.141592653;
	int num = (int)PI; //C���Է���ǿ������ת�����ɶ��ԱȽϲת���ǲ������͡�
	int num2 = static_cast<int>(PI);  //����һ����C������ʹ�õ�ǿ������ת������ ��̬ת��
	cout << "num: " << num << endl;
	cout << "num2:" << num2 << endl;
	return 0;
}