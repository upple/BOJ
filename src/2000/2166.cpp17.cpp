#include <bits/stdc++.h>
using namespace std;

struct xy{int x, y;};
xy p[10000];

double cross(double x1, double y1, double x2, double y2)
{
	return x1*y2-x2*y1;
}

int main()
{
	int n;
	cin>>n;

	for(int i=0; i<n; i++)
	{
		cin>>p[i].x>>p[i].y;
	}

	double ans=0;
	for(int i=2; i<n; i++)
	{
		double v1x=p[i-1].x-p[0].x, v1y=p[i-1].y-p[0].y, v2x=p[i].x-p[0].x, v2y=p[i].y-p[0].y;
		ans+=cross(v1x, v1y, v2x, v2y)/2;

	}

	printf("%.1lf", abs(ans));
}
