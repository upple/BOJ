#include <bits/stdc++.h>
using namespace std;

struct xyc{int x, y, c;};
int dx[]={1, 0, -1, 0};
int dy[]={0, 1, 0, -1};
int n, m;
int arr[10][10];
bool bridge[10][10], v[10][10][2];

bool check_bridge(int x, int y)
{
    bool tmp[4];
    for(int i=4; i--;)
    {
        int nx=x+dx[i], ny=y+dy[i];
        if(nx<0 || nx>=n || ny<0 || ny>=n || arr[nx][ny]) tmp[i]=0;
        else tmp[i]=1;
    }
    for(int i=4; i--;)
    {
        if(tmp[i] && tmp[(i+1)%4]) return false;
    }
    return true;
}
int bfs()
{
    queue<xyc> Q;
    v[0][0][0]=1;
    Q.push({0, 0, 0});
    int cnt=1;
    while(Q.size())
    {
        int size=Q.size();
        while(size--)
        {
            int x=Q.front().x, y=Q.front().y, c=Q.front().c;
            Q.pop();
            if(x==n-1 && y==n-1) return cnt-1;

            bool chk=false;
            for(int i=4; i--;)
            {
                int nx=x+dx[i], ny=y+dy[i];
                if(nx<0 || nx>=n || ny<0 || ny>=n || v[nx][ny][c]) continue;
                if(arr[nx][ny]==1)
                {
                    Q.push({nx, ny, c});
                    v[nx][ny][c]=1;
                }
                if(arr[x][y]!=1) continue;
                if((arr[nx][ny]==0 && bridge[nx][ny] && c==0 && !v[nx][ny][1]) || arr[nx][ny]>1)
                {
                    if(cnt%(arr[nx][ny]?arr[nx][ny]:m)==0)
                    {
                        Q.push({nx, ny, (arr[nx][ny]?c:1)});
                        v[nx][ny][(arr[nx][ny]?c:1)]=1;
                    }
                    else chk=true;
                }

            }

            if(chk==true) Q.push({x, y, c});
        }
        cnt++;
    }
    return -1;
}
int main()
{
    cin>>n>>m;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>arr[i][j];

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(arr[i][j]==0)
                bridge[i][j]=check_bridge(i, j);

    cout<<bfs();
}