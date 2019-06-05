#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long double ld;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n;
	pair<ld, int> arr[100000];
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		ld x, y, v;
		cin>>x>>y>>v;
		arr[i-1]={sqrt(x*x+y*y)/v, i};
	}

	sort(arr, arr+n);
	for(int i=0; i<n; i++)
		cout<<arr[i].second<<'\n';
}
