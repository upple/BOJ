#include <bits/stdc++.h>
using namespace std;

struct xy{double x1, y1, x2, y2;};
xy p[2000];

inline double getDistP(double x1, double y1, double x2, double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

bool checkIn(xy & a, double x, double y)
{
	double res1=((x-a.x1)*(a.x2-a.x1)+(y-a.y1)*(a.y2-a.y1))/(getDistP(x, y, a.x1, a.y1)*getDistP(a.x2, a.y2, a.x1, a.y1));
	double res2=((x-a.x2)*(a.x1-a.x2)+(y-a.y2)*(a.y1-a.y2))/(getDistP(x, y, a.x2, a.y2)*getDistP(a.x1, a.y1, a.x2, a.y2));

	return res1*res2>=0;
}

double getDist(xy & a, xy && b)
{
	double c1;
	c1=min({getDistP(a.x1, a.y1, b.x1, b.y1), getDistP(a.x2, a.y2, b.x1, b.y1), getDistP(a.x2, a.y2, b.x2, b.y2)});
	if(checkIn(a, b.x1, b.y1))
	{
		c1=min(c1, abs((b.x1-a.x1)*(a.y2-a.y1)-(a.x2-a.x1)*(b.y1-a.y1))/getDistP(a.x1, a.y1, a.x2, a.y2));
	}
	if(checkIn(a, b.x2, b.y2))
	{
		c1=min(c1, abs((b.x2-a.x1)*(a.y2-a.y1)-(a.x2-a.x1)*(b.y2-a.y1))/getDistP(a.x1, a.y1, a.x2, a.y2));
	}
	if(checkIn(b, a.x1, a.y1))
	{
		c1=min(c1, abs((a.x1-b.x1)*(b.y2-b.y1)-(b.x2-b.x1)*(a.y1-b.y1))/getDistP(b.x1, b.y1, b.x2, b.y2));
	}
	if(checkIn(b, a.x2, a.y2))
	{
		c1=min(c1, abs((a.x2-b.x1)*(b.y2-b.y1)-(b.x2-b.x1)*(a.y2-b.y1))/getDistP(b.x1, b.y1, b.x2, b.y2));
	}

	return c1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	double ans=1e9;
	cin>>n>>m;

	for(int i=0; i<n; i++)
	{
		cin>>p[i].x1>>p[i].y1>>p[i].x2>>p[i].y2;
	}

	for(int i=0; i<m; i++)
	{
		double x1, y1, x2, y2;
		cin>>x1>>y1>>x2>>y2;

		for(int j=0; j<n; j++)
		{
			ans=min(ans, getDist(p[j], {x1, y1, x2, y2}));
		}
	}

	cout.precision(11);
	cout<<ans;
}