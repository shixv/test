#include <iostream>
#include <cstring>
using namespace std;
class Array
{
	public:
		Array():_size(0),m_data(NULL){}
		Array(int size)
		{
			_size=size;
			m_data=new int[size];
		}
		~Array(){if(m_data!=NULL)delete[] m_data;}
		Array(const Array &arr){
			if(this==&arr)return;
			this->_size=arr._size;
			this->m_data=new int[_size];
			memcpy(this->m_data,arr.m_data,sizeof(int)*_size);
		}
		Array &operator=(Array &arr){
			if(this->m_data==NULL){new int[arr._size];this->_size=arr._size;}
			if(this->_size!=arr._size){
				this->_size=arr._size;
				delete[] this->m_data;
				m_data=new int[this->_size];
			}
			memcpy(this->m_data,arr.m_data,this->_size*sizeof(int));
			return *this;
		}
		int &operator[](int index)
		{
			if(index>=_size)
				return *m_data;
			return *(m_data+index); 
		}

		friend bool operator==(Array &a1,Array &a2);
		friend bool operator!=(Array &a1,Array &a2);
		friend istream &operator>>(istream &is,Array &arr);
		friend ostream &operator<<(ostream &os,Array &arr);
	private:
		int _size;
		int *m_data;
};
bool operator==(Array &a1,Array &a2)
{
	if(a1._size!=a2._size)
		return false;
	for(int i=0;i<a1._size;i++)
		if(*(a1.m_data+i)!=*(a2.m_data+i))
			return false;
	return true;
}
bool operator!=(Array &a1,Array &a2)
{
	return !(a1==a2);
}
istream &operator>>(istream &is,Array &arr)
{
	for(int i=0;i<arr._size;i++)
		is>>*(arr.m_data+i);
	return is;
}
ostream &operator<<(ostream &os,Array &arr)
{
	for(int i=0;i<arr._size;i++)
		os<<*(arr.m_data+i);
	return os;
}
int main(void)
{
	Array arr(10);
	Array arr2(2);
	for(int i=0;i<10;i++)
		arr[i]=i;
	for(int i=0;i<10;i++)
		cout<<arr[i]<<",";
	cout<<endl;
//	cin>>arr;

	cout<<arr<<endl;

	Array arr1=arr;
	cout<<(arr==arr1)<<endl;
	
	cout<<(arr==arr2)<<endl;

	return 0;
}
