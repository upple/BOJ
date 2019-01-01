#include <bits/stdc++.h>
using namespace std;

int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};
char arr[12][12], cpy[12][12];

void turn(int i, int j)
{
	cpy[i][j]=(cpy[i][j]=='O'?'#':'O');
	for(int k=4; k--;)
	{
		int nx=i+dx[k], ny=j+dy[k];
		cpy[nx][ny]=(cpy[nx][ny]=='O'?'#':'O');
	}
}
int solve()
{
	int ans=1e9;
	for(int c=0; c<1024; c++)
	{
		int cnt=0;
		memcpy(cpy, arr, sizeof(cpy));
		for(int i=0; i<10; i++)
		{
			if((c & (1<<i))!=0)
			{
				cnt++;
				turn(1, i+1);
			}
		}
		for(int i=2; i<=10; i++)
		{
			for(int j=1; j<=10; j++)
			{
				if(cpy[i-1][j]=='O')
				{
					cnt++;
					turn(i, j);
				}
			}
			
		}

		for(int i=1; i<=10; i++)
		{
			if(cpy[10][i]=='O') break;
			if(i==10) ans=min(ans, cnt);
		}
	}

	return ans==1e9?-1:ans;
}
int main()
{
	for(int i=1; i<=10; i++)
	{
		cin>>arr[i]+1;
	}

	cout<<solve();

}