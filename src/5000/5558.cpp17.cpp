#include <bits/stdc++.h>
using namespace std;

struct xy{int x, y;};
int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};
char arr[1000][1001];
bool v[1000][1000];
int h, w, n;
int sx, sy;

int bfs(char k, int x, int y)
{
    queue<xy> Q;
    memset(v, 0, h*1000);
    v[x][y]=1;
    int cnt=0;
    Q.push({x, y});
    while(Q.size())
    {
        int size=Q.size();
        while(size--)
        {
            x=Q.front().x, y=Q.front().y;
            Q.pop();
            if(arr[x][y]==k)
            {
                arr[x][y]='.';
                sx=x, sy=y;
                return cnt;
            }

            for(int i=4; i--;)
            {
                int nx=x+dx[i], ny=y+dy[i];
                if(nx<0 || nx>=h || ny<0 || ny>=w || v[nx][ny] || arr[nx][ny]=='X') continue;
                Q.push({nx, ny});
                v[nx][ny]=1;
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
    cin>>h>>w>>n;

    for(int i=0; i<h; i++)
    {
        cin>>arr[i];
        for(int j=0; j<w; j++)
        {
            if(arr[i][j]=='S')
            {
                sx=i, sy=j;
            }
        }
    }

    int ans=0;
    for(char i='1'; i<=n+'0'; i++)
    {
        ans+=bfs(i, sx, sy);
    }

    cout<<ans;
}