#include <bits/stdc++.h>
using namespace std;
struct xy{int x, y;};
const int dx[]={0, 0, 1, -1};
const int dy[]={1, -1, 0, 0};
int r, c, n;

char arr[200][201];
queue<xy> Q[3];

int bfs(int t)
{
	switch(t)
	{
		case 0:
		while(Q[2].size())
		{
			int x=Q[2].front().x, y=Q[2].front().y;
			Q[2].pop();
			arr[x][y]='.';
			for(int i=4; i--;)
			{
				int nx=x+dx[i], ny=y+dy[i];
				if(nx<0 || nx>=r || ny<0 || ny>=c) continue;
				arr[nx][ny]='.';
			}
		}
		case 1:

		while(Q[1].size())
		{
			int x=Q[1].front().x, y=Q[1].front().y;
			Q[1].pop();

			if(arr[x][y]=='O') Q[2].push({x, y});
		}

		while(Q[0].size())
		{
			int x=Q[0].front().x, y=Q[0].front().y;
			Q[0].pop();
			
			if(arr[x][y]=='O') Q[1].push({x, y});
		}

		if(t==0) break;

		for(int i=0; i<r; i++)
		{
			for(int j=0; j<c; j++)
			{
				if(arr[i][j]=='.') arr[i][j]='O', Q[0].push({i, j});
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>r>>c>>n;

	for(int i=0; i<r; i++)
	{
		cin>>arr[i];		
		for(int j=0; j<c; j++)
		{
			if(arr[i][j]=='O') Q[2].push({i, j});
		}
	}

	for(int i=1; i<n; i++)
	{
		bfs(i%2);
	}

	for(int i=0; i<r; i++)
	{
		cout<<arr[i]<<'\n';
	}
}