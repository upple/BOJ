#include <bits/stdc++.h>
#define INF 1e8
using namespace std;

struct xy{int x, y;};
vector<xy> cam;
int dx[]={0, 1, 0, -1};
int dy[]={1, 0, -1, 0};
int n, m;
int arr[8][8];
bool v[8][8];

int solve(int c, int cur)
{
	static int ans=INF;
	int x, y;
	if(c==cam.size()) return ans=min(ans, cur);
	x=cam[c].x, y=cam[c].y;

	vector<int> dir;
	switch(arr[x][y])
	{
		case 5: dir={0, 1, 2, 3}; break;
		case 4: dir={0, 1, 3}; break;
		case 3: dir={0, 1}; break;
		case 2: dir={0, 2}; break;
		case 1: dir={0}; break;
	}

	for(int i=4; i--;)
	{
		stack<xy> S;
		for(int j=0; j<dir.size(); j++)
		{
			int ddx=dx[(i+dir[j])%4], ddy=dy[(i+dir[j])%4];
			int tx=x, ty=y;
			while(1)
			{
				tx+=ddx, ty+=ddy;
				if(tx<0 || tx>=n || ty<0 || ty>=m || arr[tx][ty]==6) break;
				if(arr[tx][ty]!=0 || v[tx][ty]==1) continue;
				S.push({tx, ty});
				v[tx][ty]=1;
				cur--;
			}

		}

		ans=min(ans, solve(c+1, cur));
		while(S.size())
		{
			v[S.top().x][S.top().y]=0;
			S.pop();
			cur++;
		}
		
	}

	return ans;
}
int main()
{
	cin>>n>>m;
	int space=0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cin>>arr[i][j];
			if(arr[i][j]==0) space++;
			else if(arr[i][j]!=6) cam.push_back({i, j});
		}
	}
	cout<<solve(0, space);
}