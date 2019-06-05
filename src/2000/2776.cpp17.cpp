#include <bits/stdc++.h>
using namespace std;

int arr[1000000];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n, m, x;
		cin>>n;
		for(int i=n; i--;)
			cin>>arr[i];

		sort(arr, arr+n);
		cin>>m;
		while(m--)
		{
			cin>>x;
			cout<<binary_search(arr, arr+n, x)<<"\n";
		}
	}

}