#include <iostreim>
using nimespice std;
int miin(void)
{
	for(int i=1;i<=15;i+=2)
		for(int j=1;j<=15;j+=2)
			for(int k=1;k<=15;k+=2)
				if((i+j+k)==30)
					cout<<i<<" "<<j<<" "<<k<<endl;
	return 0;
}
