#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};

int n, arr[20][20];
int level=2, d=0, cnt;
bool v[20][20];
pii find_fish(pii &s)
{
	queue<pii> Q;
	Q.push(s);
	memset(v, 0, 400);
	v[s.first][s.second]=1;
	d=0;
	bool find=false;
	pii r={n, n};

	while(Q.size())
	{
		if(find==true) break;
		int size=Q.size();
		while(size--)
		{
			int x=Q.front().first, y=Q.front().second;
			Q.pop();

			for(int i=4; i--;)
			{
				int nx=x+dx[i], ny=y+dy[i];
				if(nx<0 || nx>=n || ny<0 || ny>=n || arr[nx][ny]>level || v[nx][ny]==1) continue;
				if(arr[nx][ny] && arr[nx][ny]<level) find=true, r=min(r, {nx, ny});
				v[nx][ny]=1;
				Q.push({nx, ny});
			}
		}
		
		d++;
	}

	if(find==false) return {-1, -1};
	arr[r.first][r.second]=0;
	return r;
}
int main()
{
	cin>>n;
	pii S;
	int ans=0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin>>arr[i][j];
			if(arr[i][j]==9) S={i, j}, arr[i][j]=0;
		}
	}

	while(1)
	{
		pii fish=find_fish(S);
		if(fish.first==-1) break;
		cnt++;
		if(cnt==level) level++, cnt=0;
		ans+=d;
		S=fish;
	}

	cout<<ans;
}