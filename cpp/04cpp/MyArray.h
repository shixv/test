//int ���͵�������
class MyArray
{
public:
	MyArray();
	MyArray(int length);
	~MyArray();
	MyArray(const MyArray & another);

	void setData(int index, int value);
	int getData(int index);

private:
	int len;
	int *space;
};

