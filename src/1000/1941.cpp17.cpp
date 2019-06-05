#include <bits/stdc++.h>
using namespace std;
const int dx[]={-1, 0, 1, 0};
const int dy[]={0, -1, 0, 1};
struct xy{int x, y;};
char arr[7][7];
bool v[7][7];
long long ans;

int bfs(int x, int y)
{
    queue<xy> Q, r;
    Q.push({x, y});
    v[x][y]=0;
    int ret=0;
    while(Q.size())
    {
        auto [x, y]=Q.front();
        Q.pop();
        r.push({x, y});
        ret++;
        for(int i=4; i--;)
        {
            int nx=x+dx[i], ny=y+dy[i];
            if(v[nx][ny])
            {
                Q.push({nx, ny});
                v[nx][ny]=0;
            }
        }
    }

    while(r.size())
    {
        auto &[x, y]=r.front();
        v[x][y]=1;
        r.pop();
    }
    return ret;
    
}
void solve(int x, int y, int c, int u)
{
    if(u==4) return;
    if(c==7)
    {
        ans+=(bfs(x, y)==7);
        return;
    }
    for(int i=x; i<=5; i++)
    {
        for(int j=y+1; j<=5; j++)
        {
            v[i][j]=1;
            solve(i, j, c+1, u+(arr[i][j]=='Y'));
            v[i][j]=0;
        }
        y=0;
    }
}
int main()
{
    for(int i=1; i<=5; i++)
    {
        cin>>arr[i]+1;
    }

    solve(1, 0, 0, 0);
    cout<<ans;
}