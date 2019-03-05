#include <bits/stdc++.h>
using namespace std;

struct xy{int x, y;};
const int dx[]={0, 0, 1, -1};
const int dy[]={1, -1, 0, 0};

char arr[1002][1002];
int v[1002][1002];
int s[1000000];
int c;
void bfs(int x, int y)
{
	c++;
	queue<xy> Q;
	v[x][y]=c;
	int size=0;
	Q.push({x, y});
	while(Q.size())
	{
		x=Q.front().x, y=Q.front().y;
		Q.pop();
		size++;

		for(int i=4; i--;)
		{
			int nx=x+dx[i], ny=y+dy[i];
			if(arr[nx][ny]!='0' || v[nx][ny]) continue;
			Q.push({nx, ny});
			v[nx][ny]=c;
		}
	}

	s[c]=size;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin>>n>>m;

	for(int i=1; i<=n; i++)
		cin>>arr[i]+1;

	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			if(arr[i][j]=='0' && !v[i][j]) bfs(i, j);
		}
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			if(arr[i][j]=='0') cout<<0;
			else
			{
				set<int> S;
				int ret=1;
				for(int k=4; k--;)
				{
					int nx=i+dx[k], ny=j+dy[k];
					if(arr[nx][ny]=='0' && S.find(v[nx][ny])==S.end()) ret+=s[v[nx][ny]];
					S.insert(v[nx][ny]);
				}
				cout<<ret%10;
			}
		}

		cout<<'\n';
	}
}