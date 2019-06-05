#include <bits/stdc++.h>
using namespace std;

int n;
const int dx[]={0, 0, 1, -1, 0};
const int dy[]={1, -1, 0, 0, 0};
int arr[12][12];
bool v[12][12];

int solve(int x, int y, int p, int c)
{
    if(p==3) return c;
    int ret=1e9;
    for(int i=x; i<n; i++)
    {
        for(int j=y; j<n; j++)
        {
            bool chk=true;
            for(int k=5; k--;)
            {
                int nx=i+dx[k], ny=j+dy[k];
                if(v[nx][ny])
                {
                    chk=false;
                    break;
                }
            }

            if(chk==false) continue;
            int t=0;
            for(int k=5; k--;)
            {
                int nx=i+dx[k], ny=j+dy[k];
                v[nx][ny]=1;
                t+=arr[nx][ny];
            }

            ret=min(ret, solve(i, j+3, p+1, c+t));
            for(int k=5; k--;)
            {
                int nx=i+dx[k], ny=j+dy[k];
                v[nx][ny]=0;
            }
        }

        y=2;
    }

    return ret;
}
int main()
{
    cin>>n;
    memset(arr, -1, sizeof(arr));

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin>>arr[i][j];
        }
    }

    cout<<solve(2, 2, 0, 0);
}