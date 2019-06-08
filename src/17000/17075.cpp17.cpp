#include <bits/stdc++.h>
using namespace std;

int arr[50][50];

vector<pair<int, pair<int, int> > > v;
char dp[2500][2500];

int n, m, k;

bool solve(int p, int c)
{
    if(p<0) return false;
    if(dp[p][c]!=-1) return dp[p][c];
    if(solve(p-1, c))
    {
        return dp[p][c]=1;
    }
    if(solve(p-1, (c+k-v[p].first)%k))
    {
        arr[v[p].second.first][v[p].second.second]=1;
        return dp[p][c]=1;
    }
    dp[p][c]=0;
    return false;
}
int main()
{
    v.push_back({0, {0, 0}});
    cin>>n>>m>>k;
    memset(dp, -1, sizeof(dp));
    int o=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            int &x=arr[i][j];
            cin>>x;
            if(x==1) o+=(i+1)*(n-i)*(j+1)*(m-j);
            else if(x==-1)
            {
                v.push_back({(i+1)*(n-i)*(j+1)*(m-j)%k, {i, j}});
                x=0;
            }
        }
    }

    dp[0][o%k]=1;
    if(solve(v.size()-1, 0))
    {
        cout<<1<<'\n';
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cout<<arr[i][j]<<' ';
            }
            cout<<'\n';
        }
    }
    else cout<<-1;
}