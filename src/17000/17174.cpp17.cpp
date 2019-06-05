#include <iostream>
using namespace std;

int main()
{
	int n, m;
	int ans=0;
	cin>>n>>m;

	while(n)
	{
		ans+=n;
		n=n/m;
	}

	cout<<ans;
}