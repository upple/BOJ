#include <bits/stdc++.h>
using namespace std;
struct xy{int x, y;};
const int dx[]={0, 0, 1, -1};
const int dy[]={1, -1, 0, 0};

int n, m, p;
queue<xy> Q[10];
int s[10], ans[10];
char arr[1002][1002];

bool bfs()
{
	bool chk=false;

	for(int i=1; i<=p; i++)
	{
		for(int j=0; j<s[i]; j++)
		{
			int size=Q[i].size();
			if(!size) break;
			while(size--)
			{
				int x=Q[i].front().x, y=Q[i].front().y;
				Q[i].pop();
				for(int k=4; k--;)
				{
					int nx=x+dx[k], ny=y+dy[k];
					if(arr[nx][ny]!='.') continue;
					Q[i].push({nx, ny});
					arr[nx][ny]=arr[x][y];
					ans[arr[x][y]-'0']++;
					chk=true;
				}
			}
		}
	}

	return chk;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m>>p;
	for(int i=1; i<=p; i++)
		cin>>s[i];

	for(int i=1; i<=n; i++)
	{
		cin>>arr[i]+1;
		for(int j=1; j<=m; j++)
		{
			if(isdigit(arr[i][j]))
			{
				ans[arr[i][j]-'0']++;
				Q[arr[i][j]-'0'].push({i, j});
			}
		}
	}

	while(bfs());

	for(int i=1; i<=p; i++)
		cout<<ans[i]<<' ';
}