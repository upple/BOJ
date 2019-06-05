#include <bits/stdc++.h>
using namespace std;
struct xy{int x, y;};
vector<xy> chk[3];
bool arr[32][32];
long long dp[32][32][3];
const int dx[]={0, 1, 1};
const int dy[]={1, 1, 0};
int n;

long long solve(int x, int y, int d)
{
    if(dp[x][y][d]!=-1) return dp[x][y][d];
    if(x==n-1 && y==n-1) return 1;
    dp[x][y][d]=0;
    for(int nd=3; nd--;)
    {
        if(abs(nd-d)>1) continue;
        int nx=x+dx[nd], ny=y+dy[nd];
        if(nx<0 || nx>=n || ny<0 || ny>=n || arr[nx][ny]==1) continue;
        if(dp[nx][ny][nd]!=-1)
        {
            dp[x][y][d]+=dp[nx][ny][nd];
            continue;
        } 
        bool psb=true;
        for(auto &[px, py] : chk[nd])
        {
            int ax=x+px, ay=y+py;
            if(ax<0 || ax>=n || ay<0 || ay>=n) continue;
            
            if(arr[ax][ay]==1)
            {
                psb=false;
                break;
            }
        
        }

        if(psb==true)
        {
            dp[x][y][d]+=solve(nx, ny, nd);
        }
    }

    return dp[x][y][d];
}
int main()
{
    cin>>n;

    chk[0]={};
    chk[1]={{0, 1}, {1, 0}};
    chk[2]={};
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cin>>arr[i][j];
    }
    cout<<solve(0, 1, 0);
}