#include <bits/stdc++.h>
using namespace std;

bool isPellendrome(string &str)
{
    for(int i=0; i<str.size()/2; i++)
    {
        if(str[i]!=str[str.size()-i-1])
            return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                string union_str=arr[i]+arr[j], union_str2=arr[j]+arr[i];
                if(isPellendrome(union_str))
                {
                    cout<<union_str<<"\n";
                    goto out;
                }
                if(isPellendrome(union_str2))
                {
                    cout<<union_str2<<"\n";
                    goto out;
                }
            }
        }

        cout<<0<<"\n";
        out:;
    }
}