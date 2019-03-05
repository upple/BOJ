#include <bits/stdc++.h>
using namespace std;

struct cxy{long long c; int x, y;};
bool operator <(cxy &a, cxy &b)
{
	return a.c>b.c;
}
long long row[1000], col[1000];
cxy arr[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	int n, m;
	cin>>n>>m;
	long long sum=0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			long long x;
			cin>>x;
			sum+=x;
			arr[i*m+j]={x, i, j};
		}
	}

	sort(arr, arr+n*m);
	int remain=n+m;
	for(int i=0; remain; i++)
	{
		if(!row[arr[i].x] || !col[arr[i].y])
		{
			remain-=(row[arr[i].x]==0)+(col[arr[i].y]==0);
			row[arr[i].x]=max(row[arr[i].x], arr[i].c);
			col[arr[i].y]=max(col[arr[i].y], arr[i].c);
			sum-=arr[i].c;
		}
	}

	cout<<sum;
}