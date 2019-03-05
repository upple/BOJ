#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	cin>>n>>k;

	if(k>1 && k%2)
	{
		cout<<"ERROR";
		return 0;
	}

	if(n>0 && k==0)
	{
		cout<<"INFINITE";
		return 0;
	}

	if(n<0 && k==1)
	{
		cout<<"INFINITE";
		return 0;
	}

	if(n<=0)
	{
		cout<<0;
		return 0;
	}

	if(n>0 && k==1)
	{
		cout<<0;
		return 0;
	}
	
	k/=2;
	n-=k;
	cout<<(n/k)+(n%k!=0);
}