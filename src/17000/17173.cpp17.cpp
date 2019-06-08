#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin>>n>>m;
	int ans=0;
	bool chk[1001]={};
	while(m--)
	{
		int x;
		cin>>x;

		for(int i=x; i<=n; i+=x)
		{
			if(chk[i]==0) ans+=i;
			chk[i]=1;
		}

	}

	cout<<ans;
}