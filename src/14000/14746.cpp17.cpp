#include <bits/stdc++.h>
using namespace std;

int arr[500003];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, c1, c2;
	cin>>n>>m>>c1>>c2;

	for(int i=1; i<=n; i++)
	{
		cin>>arr[i];
	}

	sort(arr+1, arr+n+1);
	arr[0]=-1e9;
	arr[n+1]=1e9;

	int min_v=1e9, cnt=0;

	for(int i=0; i<m; i++)
	{
		int x;
		cin>>x;
		int *it=lower_bound(arr+1, arr+n+1, x);
		int val=abs(x-*it);
		if(min_v>val) min_v=val, cnt=1;
		else if(min_v==val) cnt++;
		it--;
		val=abs(x-*it);
		if(min_v>val) min_v=val, cnt=1;
		else if(min_v==val) cnt++;
	}

	cout<<min_v+abs(c1-c2)<<" "<<cnt;
}