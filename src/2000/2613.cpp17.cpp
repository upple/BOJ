#include <bits/stdc++.h>
using namespace std;

int arr[301];
int main()
{
    int n, m;
    cin>>n>>m;

    int l=0, r=30000;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        l=max(l, arr[i]);
    }
    arr[n]=1e9;
    int ans=r;
    while(l<=r)
    {
        bool chk=true;
        int mid=l+r>>1;
        int cur=0, sum=mid+1;
        for(int i=0; i<n; i++)
        {
            if(sum+arr[i]>mid)
            {
                cur++;
                sum=0;
                if(cur>m)
                {
                    chk=false;
                    break;
                }
            }
            sum+=arr[i];
        }

        if(chk)
        {
            ans=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
        
    }

    cout<<ans<<"\n";
    int cur=0, sum=0;
    int cnt=0;
    for(int i=0; i<n; i++)
    {
        sum+=arr[i];
        cur++;
        if(m-cnt==n-i || sum+arr[i+1]>ans)
        {
            cout<<cur<<' ';
            cnt++;
            cur=0;
            sum=0;
        }
    }
}