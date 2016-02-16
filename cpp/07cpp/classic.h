class Cd
{
  private:
	char performers[50];
	char label[20];
	int selections;
	double playtime;
  public:
	Cd(char *s1,char *s2,int n,double x);
	Cd(const Cd &d);
	Cd();
//	virtual ~Cd();
	virtual void Report()const;
	virtual Cd &operator=(const Cd &d);
};
Cd &Cd::operator=(const Cd &d)
{
  strcpy(performers,d.performers);
  strcpy(label,d.label);
  selections=d.selections;
  playtime=d.playtime;
  return this;
}
Cd::Cd(char *s1,char *s2,int n,double x)
{
  strcpy(performers,s1);
  strcpy(label,s2);
  selections=n;
  playtime=x;
}
void Cd::Report(void)const
{
  cout<<"performers is "<<performers<<endl;
  cout<<"label is "<<label<<endl;
  cout<<"selections is "<<selections<<endl;
  cout<<"playtime is "<<playtime<<endl;
}
Cd::Cd(const Cd &d)
{
  strcpy(performers,d.performers);
  strcpy(label,d.label);
  selections=d.selections;
  playtime=d.playtime;
}
class Classic:public Cd
{
  private:
	char favo[100];
  public:
	Classic(char *s1,char *s2,char *s3,int n,double x);
	Classic(const Classic &d);
	Classic();
};
Classic::Classic(char *s1,char *s2,char *s3,int n,double x):Cd(s1,s2,n,x)
{
  strcopy(favo,s3);
}
void Classic::Report(void)const
{
  Cd::report();
  cout<<"favo is "<<favo<<endl;
}
Classic::Classic(const Classic &d)
{
  strcpy(performers,d.performers);
  strcpy(label,d.label);
  strcpy(favo,d.favo);
  selections=d.selections;
  playtime=d.playtime;
}
Classic &Classic::operator=(const Classic &d)
{
  strcpy(performers,d.performers);
  strcpy(label,d.label);
  strcpy(favo,d.favo);
  selections=d.selections;
  playtime=d.playtime;
  return this;
}
