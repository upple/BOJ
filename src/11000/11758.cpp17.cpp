#include <bits/stdc++.h>
using namespace std;

int func(int x1, int y1, int x2, int y2)
{
	int res=x1*y2-x2*y1;
	if(res==0) return 0;
	if(res<0) return -1;
	return 1;
}

int main()
{
	int x1, y1, x2, y2, x3, y3;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	cout<<func(x2-x1, y2-y1, x3-x2, y3-y2);
}