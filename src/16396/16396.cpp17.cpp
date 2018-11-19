#include <bits/stdc++.h>
using namespace std;

pair<int, int> arr[10000];

int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int x, y;
        cin>>x>>y;
        arr[i]={x, y};
    }

    sort(arr, arr+n);

    int ans=0;
    int l=arr[0].first, r=arr[0].second;
    for(int i=1; i<n; i++)
    {
        int x=arr[i].first, y=arr[i].second;
        if(x>r)
        {
            ans+=r-l;
            l=x, r=y;
        }
        else if(y>r)
        {
            r=y;
        }
    }

    ans+=r-l;
    cout<<ans;
}