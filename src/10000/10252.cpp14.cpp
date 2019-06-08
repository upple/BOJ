#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin>>t;
	while(t--)
	{
		int n, m;
		cin>>n>>m;
		cout<<"1\n";
		for(int i=0; i<m; i++)
		{
			cout<<"(0,"<<i<<")\n";
		}

		for(int i=1; i<n; i++)
		{
			cout<<"("<<i<<","<<m-1<<")\n";
		}

		for(int i=0; i<=m-2; i++)
		{
			if(i%2)
			{
				for(int j=1; j<n; j++)
				{
					cout<<"("<<j<<","<<m-i-2<<")\n";
				}
			}
			else
			{
				for(int j=n-1; j>0; j--)
				{
					cout<<"("<<j<<","<<m-i-2<<")\n";
				}
			}
		}
	}
}