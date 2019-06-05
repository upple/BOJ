#include <bits/stdc++.h>
using namespace std;

int arr[2][2000], dp[2000][2000];
bool v[2000][2000];
int n;
int solve(int x, int y)
{
    if(x>=n || y>=n) return 0;
    if(v[x][y]) return dp[x][y];
    if(arr[1][x]<arr[0][y]) dp[x][y]=arr[1][x]+solve(x+1, y);

    v[x][y]=1;
    return dp[x][y]=max({dp[x][y], solve(x+1, y+1), solve(x, y+1)});
}
int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>arr[0][i];
    
    for(int i=0; i<n; i++)
        cin>>arr[1][i];

    cout<<solve(0, 0);
}