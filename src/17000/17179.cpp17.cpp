#include <bits/stdc++.h>
using namespace std;

int n, m, l;
int s[1000];
int q[1000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>m>>l;

    for(int i=0; i<m; i++)
        cin>>s[i];

    for(int i=0; i<n; i++)
        cin>>q[i];

    for(int i=0; i<n; i++)
    {
        int left=0, right=l/(q[i]+1);
        int ans=0;
        while(left<=right)
        {
            int mid=left+right>>1;
            int cur=0, cut=0;
            for(int j=0; j<m; j++)
            {
                if(s[j]-cur>=mid)
                {
                    cur=s[j];
                    cut++;
                }
                
            }
            if(l-cur>=mid) cut++;
            if(cut>q[i])
            {
                left=mid+1;
                ans=max(ans, mid);
            }
            else
            {
                right=mid-1;
            }
            
        }

        cout<<ans<<"\n";
    }
}