#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int x, n;
	while(cin>>x>>n)
	{
		x*=10000000;
		for(int i=0; i<n; i++)
		{
			cin>>arr[i];
		}

		sort(arr, arr+n);

		bool chk=false;
		for(int i=0, j=n-1;i<j; i++)
		{
			while(arr[j]>x-arr[i] && i<j) j--;
			if(i>=j) break;

			if(arr[j]==x-arr[i])
			{
				chk=true;
				cout<<"yes "<<arr[i]<<" "<<arr[j]<<"\n";
				break;
			}
		}

		if(!chk) cout<<"danger\n";
	}
}