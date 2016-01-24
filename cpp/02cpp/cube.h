class Cube
{
	private:
		double a;
		double b;
		double c;
	public:
		double getArea(void);
		double getVolume(void);
		void setabc(double,double,double);
		void getabc(double &,double &,double &);
		bool compare(Cube &);
		void printabc(void);
};
