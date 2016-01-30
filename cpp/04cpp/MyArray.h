//int 类型的数组类
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

