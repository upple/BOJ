#include <bits/stdc++.h>
using namespace std;

int sum[1001][1001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	int r, c, q, x;
	cin>>r>>c>>q;
	for(int i=1; i<=r; i++)
	{
		for(int j=1; j<=c; j++)
		{
			cin>>x;
			sum[i][j]=sum[i][j-1]+x;
		}
	}

	while(q--)
	{
		int x1, x2, y1, y2, res=0;
		cin>>x1>>y1>>x2>>y2;
		for(int i=x1; i<=x2; i++)
		{
			res+=sum[i][y2]-sum[i][y1-1];
		}

		cout<<res/((x2-x1+1)*(y2-y1+1))<<"\n";
	}
}