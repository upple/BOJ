#include <bits/stdc++.h>
#define MAX 500001
#define INF 1e9
using namespace std;

vector<int> st;
int n, s;
struct abc{int x[3];};
inline bool operator <(abc &a, abc &b)
{
	return a.x[0]<b.x[0];
}
abc arr[MAX];

void update(int p, int x)
{
	p+=s;
	while(p)
	{
		st[p]=min(st[p], x);
		p>>=1;
	}
}

int query(int l, int r, int p, int x, int y)
{
	if(l>y || r<x) return INF;
	if(l<=x && r>=y) return st[p];
	int mid=(x+y)>>1;
	return min(query(l, r, p<<1, x, mid), query(l, r, (p<<1)+1, mid+1, y));
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	s=1<<int(ceil(log2(n)));
	st.assign(2*s+1, INF);
	for(int i=0; i<3; i++)
		for(int j=1; j<=n; j++)
		{
			int x;
			cin>>x;
			arr[x].x[i]=j;
		}

	sort(arr+1, arr+n+1);
	int ans=0;
	for(int i=1; i<=n; i++)
	{
		if(query(1, arr[i].x[1], 1, 1, s)>arr[i].x[2]) ans++;
		update(arr[i].x[1]-1, arr[i].x[2]);
	}

	cout<<ans;
}