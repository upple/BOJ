#include <bits/stdc++.h>
using namespace std;
struct xyd{int x, y, d;};
int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};
char arr[1000][1000];
char v[1000][1000][2];
int n, m;

int bfs()
{
    queue<xyd> Q;
    queue<int> P;
    Q.push({0, 0, 0});
    v[0][0][0]=1;
    int cnt=0;
    while(Q.size())
    {
        int size=Q.size();
        while(size--)
        {
            int x=Q.front().x, y=Q.front().y, d=Q.front().d, c=-1;
            Q.pop();
            if(x==n-1 && y==m-1) return cnt;
            if(arr[x][y]=='4')
            {
                d=0;
                c=P.front();
                P.pop();
                int nx=x+dx[c], ny=y+dy[c];
                if(nx<0 || nx>=n || ny<0 || ny>=m || arr[nx][ny]=='0' || arr[nx][ny]=='3') c=-1;
            }
            if(arr[x][y]=='2')
            {
                d=1;
            }
            for(int i=4; i--;)
            {
                int nx=x+dx[i], ny=y+dy[i];
                
                if(c!=-1 && arr[x][y]=='4' && c!=i) continue;
                if(nx<0 || nx>=n || ny<0 || ny>=m || arr[nx][ny]=='0') continue;
                if((v[nx][ny][d] & (1<<i))!=0) continue;

                if(arr[nx][ny]=='3' && d==0) continue;
                if(arr[nx][ny]=='4') P.push(i);
                Q.push({nx, ny, d});
                v[nx][ny][d]+=(1<<i);
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
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>arr[i][j];
        }
    }

    cout<<bfs();
}