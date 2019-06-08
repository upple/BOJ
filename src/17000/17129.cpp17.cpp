#include <bits/stdc++.h>
#define xy(x, y) (((x)<<12) | (y))
using namespace std;
const int dx[]={0, 0, 1, -1};
const int dy[]={1, -1, 0, 0};
char arr[3002][3002];
bool v[3002][3002];
int n, m;
int sx, sy;

int bfs()
{
    queue<int> Q;
    Q.push(xy(sx, sy));
    v[sx][sy]=1;
    int cnt=0;
    while(Q.size())
    {
        for(int size=Q.size(); size--;)
        {
            int x=Q.front()>>12, y=Q.front() & 0xfff;
            Q.pop();

            if(arr[x][y]!='0') return cnt;
            for(int i=4; i--;)
            {
                int nx=x+dx[i], ny=y+dy[i];
                if(arr[nx][ny] && arr[nx][ny]!='1' && !v[nx][ny])
                {
                    Q.push(xy(nx, ny));
                    v[nx][ny]=1;
                }
            }
        }

        cnt++;
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>m;

    for(int i=1; i<=n; i++)
    {
        cin>>arr[i]+1;
        for(int j=1; j<=m; j++)
        {
            if(arr[i][j]=='2')
            {
                sx=i, sy=j;
                arr[i][j]='0';
            }
        }
    }

    int ans=bfs();
    if(ans==-1) cout<<"NIE";
    else cout<<"TAK\n"<<ans;
}