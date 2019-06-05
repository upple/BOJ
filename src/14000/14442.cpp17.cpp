#include <bits/stdc++.h>
using namespace std;

int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};
struct xyc {int x, y, c;};

char arr[1000][1001];
bool v[1000][1000][11];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin>>n>>m>>k;

	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}

	queue<xyc> Q;
	Q.push({0, 0, 0});
	int cnt=1;
	v[0][0][0]=1;
	while(Q.size())
	{
		int size=Q.size();
		while(size--)
		{
			int x=Q.front().x, y=Q.front().y, c=Q.front().c;
			Q.pop();
			if(x==n-1 && y==m-1) 
			{
				cout<<cnt;
				return 0;
			}

			for(int i=4; i--;)
			{
				int nx=x+dx[i], ny=y+dy[i];
				if(nx<0 || nx>=n || ny<0 || ny>=m || c+(arr[nx][ny]=='1')>k || v[nx][ny][c+(arr[nx][ny]=='1')]) continue;
				v[nx][ny][c+(arr[nx][ny]=='1')]=1;
				Q.push({nx, ny, c+(arr[nx][ny]=='1')});
			}
		}
		cnt++;
	}

	cout<<-1;
}
