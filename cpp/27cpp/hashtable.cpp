template <typename HashedObj>
class HashTable
{
	public:
		explicit HashTable(int size=101);

		bool contains(const HashedObj& x)const
		{
			const list<HashedObj>& whichList=theLists[myhash(x)];
			return find(whichList.begin(),whichList.end(),x)!=which.end();
		}

		void makeEmpty(void)
		{
			for(int i=0;i<theLists.size();i++)
				theLists[i].clear();
		}
		void insert(const HashedObj& x)
		{
			list<HashedObj>& whichList=theLists[myhash(x)];
			if(find(whichList.begin(),whichList.end(),x)!=whichList.end())
				return false;
			whichList.push_back(x);

			if(++currentSize>theLists.size())
				rehash();
			return true;
		}
		void remove(const HashedObj& x)
		{
			list<HashedObj>& whichList=theLists[myhash(x)];
			list<hashedObj>::iterator itr=find(whichList.begin(),whichList.end(),x);
			
			if(itr==whichList.end())
				return false;

			whichList.erase(itr);
			--currentSize;
			return true;
		}

	private:
		vector<list<HashedObj>> theLists;
		int currentSize;
		
		void rehash(void);
		int myhash(const HashedObj& x)const
		{
			int hashVal=hash(x);

			hashVal%=theLists.size();
			if(hashVal<0)
				hashVal+=theLists.size();

			return hashVal;
		}
};
int hash(const string& key);
int hash(int key);
class Employee
{
	public:
		const string& getName(void)const{return name;}
		bool operator==(const Employee& rhs)const
		{
			return getName()==rhs.getName();
		}
		bool operator!=(const Employee& rhs)const
		{
			return !(*this==rhs);
		}
	private:
		string name;
		double salary;
		int seniority;
};
int hash(const Employee& item)
{
	return hash(item.getName());
}
