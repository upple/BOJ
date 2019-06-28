#include <bits/stdc++.h>
using namespace std;

pair<int, int> arr[100000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	int n, m;
    cin>>n>>m;

    for(int i=0; i<n; i++)
    {
        int a, b;
        cin>>a>>b;
        arr[i]={a, b};
    }

    sort(arr, arr+n);

    int cur=0;
    long long ans=0;
    for(int i=0; i<n; i++)
    {
        ans+=max(0, arr[i].second-cur);
        cur=arr[i].second;
    }

    cout<<ans;
}