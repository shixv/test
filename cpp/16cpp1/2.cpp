class Employee
{
	public:
		const string& getName()const{
			return name;
		}
		bool operator==(const Employee& rhs)const{
			return getName()==rhs.getName();
		}
		bool operator!=(const Employee& rhs)const{
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
