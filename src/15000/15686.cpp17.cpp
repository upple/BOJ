#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

struct xy{int x, y;};
int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};

int arr[50][50];
bool v[50][50];
int n, m;
vector<xy> pos, cur;

int solve(int c, int it)
{
	if(c==m)
	{
		queue<xy> Q;
		int res=0, cnt=0;
		memset(v, 0, 50*n);
		for(auto &i : cur)
			Q.push(i);

		while(Q.size())
		{
			int size=Q.size();
			cnt++;
			while(size--)
			{
				int x=Q.front().x, y=Q.front().y;
				Q.pop();
				for(int i=4; i--;)
				{
					int nx=x+dx[i], ny=y+dy[i];
					if(nx<0 || nx>=n || ny<0 || ny>=n || v[nx][ny]) continue;
					v[nx][ny]=1;
					if(arr[nx][ny]==1) res+=cnt;
					Q.push({nx, ny});
				}
			}
			
		}

		return res;
	}

	int ret=INF;
	for(int i=it; i<pos.size(); i++)
	{
		cur.push_back(pos[i]);
		ret=min(ret, solve(c+1, i+1));
		cur.pop_back();
	}

	return ret;
}
int main()
{
	cin>>n>>m;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin>>arr[i][j];
			if(arr[i][j]==2) pos.push_back({i, j});
		}

	}

	cout<<solve(0, 0);

	
}