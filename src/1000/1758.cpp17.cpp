#include <bits/stdc++.h>
using namespace std;

int arr[100000];
int main()
{
	int n;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}

	sort(arr, arr+n);

	long long ans=0;
	for(int i=0; i<n; i++)
	{
		ans+=max(arr[i]-n+i+1, 0);
	}

	cout<<ans;
}