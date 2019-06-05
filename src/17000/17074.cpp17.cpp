#include <bits/stdc++.h>
using namespace std;

int dp[2][100002];
int arr[100002];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>arr[i];

    dp[0][1]=dp[1][1]=1;
    if(arr[2]<arr[1]) dp[1][2]=1;
    for(int i=1; i<n; i++)
    {
        if(arr[i+2]>=arr[i])
        {
            dp[1][i+2]+=dp[0][i];
        }
        if(arr[i+1]>=arr[i])
        {
            dp[1][i+1]+=dp[1][i];
            dp[0][i+1]+=dp[0][i];
        }
        
    }
    cout<<dp[1][n]+dp[0][n-1];
}