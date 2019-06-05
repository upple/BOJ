#include <bits/stdc++.h>
using namespace std;

struct xy{int x, y;};
int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};

int n, m, k;
int arr[1001][1002];
bool v[1001][1002];
int bfs(int c)
{
    queue<xy> Q;
    int cnt=0;
    memset(v, 0, sizeof(v));
    Q.push({0, 0});
    v[0][0]=1;
    while(Q.size())
    {
        int x=Q.front().x, y=Q.front().y;
        Q.pop();
        cnt++;
        for(int i=4; i--;)
        {
            int nx=x+dx[i], ny=y+dy[i];
            if(nx<0 || nx>n || ny<0 || ny>m+1 || v[nx][ny] || arr[nx][ny]>c) continue;
            Q.push({nx, ny});
            v[nx][ny]=1;

        }
    }

    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;

    int l=1, r=-1;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>arr[i][j];
            r=max(r, arr[i][j]);
        }
    }

    int ans=1e9, limit=m+n+n+2;
    while(l<=r)
    {
        int mid=l+r>>1;
        int ret=bfs(mid);
        if(ret-limit>=k)
        {
            ans=min(ans, mid);
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }

    cout<<ans;
}