#include <bits/stdc++.h>
using namespace std;

int n, m;
const int dx[]={0, 0, 1, -1};
const int dy[]={1, -1, 0, 0};
bool arr[1002][1002];
int v[1002][1002];
int c;
int s[1000000];

void bfs(int x, int y)
{
    c++;
    int size=0;
    queue<int> Q;
    Q.push((x<<10)+y);
    v[x][y]=c;
    while(Q.size())
    {
        int x=Q.front()>>10, y=Q.front()&0x3ff;
        Q.pop();
        size++;
        for(int i=4; i--;)
        {
            int nx=x+dx[i], ny=y+dy[i];
            if(arr[nx][ny]==0 || v[nx][ny]) continue;
            v[nx][ny]=c;
            Q.push((nx<<10)+ny);
        }
    }

    s[c]=size;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>arr[i][j];
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(arr[i][j]==1 && !v[i][j])
            {
                bfs(i, j);
            }
        }
    }

    int ans=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(arr[i][j]==0)
            {
                int ret=1;
                set<int> S;
                for(int k=4; k--;)
                {
                    int nx=i+dx[k], ny=j+dy[k];
                    if(arr[nx][ny]==1 && S.find(v[nx][ny])==S.end())
                    {
                        ret+=s[v[nx][ny]];
                    }
                    S.insert(v[nx][ny]);
                }

                ans=max(ans, ret);
            }
        }
    }

    cout<<ans;
}