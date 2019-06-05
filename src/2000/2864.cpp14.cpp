#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a, b;
	string c, d, e, f;

	cin>>a>>b;
	c=e=a, d=f=b;

	for(int i=0; i<a.size(); i++)
	{
		if(a[i]=='5')
			c[i]='6';

		else if(a[i]=='6')
			e[i]='5';
	}

	for(int i=0; i<b.size(); i++)
	{
		if(b[i]=='5')
			d[i]='6';

		else if(b[i]=='6')
			f[i]='5';
	}
    
    
	cout<<stoi(e)+stoi(f)<<endl<<stoi(c)+stoi(d)<<endl;
}
