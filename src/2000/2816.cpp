#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, k1, k2;
	string ch;
	cin>>n;
	for(int i=0; i<n;i++)
	{
		cin>>ch;
		if(ch=="KBS1")
			k1=i;
		else if(ch=="KBS2")
			k2=i;
	}
	if(k2<k1)
		k2++;
	
	int t=0;
	while(t!=k1)
	{
		cout<<1;
		t++;
	}
	while(t)
	{
		cout<<4;
		t--;
	}
    if(k2==1)
        return 0;
	while(t!=k2)
	{
		cout<<1;
		t++;
	}
	while(t!=1)
	{
		cout<<4;
		t--;
	}
}