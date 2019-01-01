#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct line{ll x1, y1, x2, y2;};
line s[3001];
int p[3001];
int c[3001];

ll cross(ll x1, ll y1, ll x2, ll y2)
{
	return x1*y2-x2*y1;
}

ll dot(ll x1, ll y1, ll x2, ll y2)
{
	return x1*x2+y1*y2;
}
bool chkMeet(line &a, line &b)
{
	ll c=cross(a.x2-a.x1, a.y2-a.y1, b.x1-a.x1, b.y1-a.y1), d=cross(a.x2-a.x1, a.y2-a.y1, b.x2-a.x1, b.y2-a.y1);
	ll e=cross(b.x2-b.x1, b.y2-b.y1, a.x1-b.x1, a.y1-b.y1), f=cross(b.x2-b.x1, b.y2-b.y1, a.x2-b.x1, a.y2-b.y1);
	if(!c && !d)
	{
		return (dot(a.x2-a.x1, a.y2-a.y1, b.x1-a.x2, b.y1-a.y2)<=0 || dot(a.x2-a.x1, a.y2-a.y1, b.x2-a.x2, b.y2-a.y2)<=0)
		&& (dot(a.x1-a.x2, a.y1-a.y2, b.x2-a.x1, b.y2-a.y1)<=0 || dot(a.x1-a.x2, a.y1-a.y2, b.x1-a.x1, b.y1-a.y1)<=0);
	}

	return c*d<=0 && e*f<=0;
}

int Find(int x)
{
	if(x==p[x]) return x;
	return p[x]=Find(p[x]);
}

void Union(int i, int j)
{
	if(p[i]>p[j]) p[p[i]]=p[j];
	else p[p[j]]=p[i];
}

int main()
{
	int n;
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>s[i].x1>>s[i].y1>>s[i].x2>>s[i].y2;
		p[i]=i;
		for(int j=1; j<i; j++)
		{
			if(Find(i)!=Find(j) && chkMeet(s[i], s[j]))
			{
				Union(i, j);
			}
		}
	}

	int r1=0, r2=0;
	for(int i=1; i<=n; i++)
	{
		if(!c[Find(i)]) r1++;
		r2=max(r2, ++c[p[i]]);
	}
	cout<<r1<<'\n'<<r2;
}