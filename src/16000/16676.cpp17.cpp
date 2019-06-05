#include <iostream>
using namespace std;

int main()
{
	long long n;
	cin>>n;
	long long ans=0, k=1;
	if(n==0)
	{
		cout<<1;
		return 0;
	}
	while(n>=k)
	{
		k=k*10+1;
		ans++;
	}

	cout<<ans;
}