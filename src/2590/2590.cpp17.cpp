#include <bits/stdc++.h>
using namespace std;

int a[7];
bool blank()
{
	for(int i=1; i<=6; i++)
	{
		if(a[i]) return false;
	}

	return true;
}

void solve(int w, int h)
{
	for(int i=min(w, h); i>0; i--)
	{
		if(a[i])
		{
			a[i]--;
			solve(w-i, h);
			solve(i, h-i);
			break;
		}
	}
}
int main()
{
	for(int i=1; i<=6; i++)
		cin>>a[i];

	int ans=0;
	while(!blank())
	{
		ans++;
		if(a[3]==1 && a[2]>=5)
		{
            solve(4, 4);
			solve(6, 2);
			solve(2, 4);
		}
		else
			solve(6, 6);
	}

	cout<<ans;
}