#include <bits/stdc++.h>
using namespace std;

struct xy{int x, y;};

int n, m;
char arr[1002][1002];
int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};

queue<xy> J, F;

void fire()
{
    int size=F.size();
    while(size--)
    {
        int x=F.front().x, y=F.front().y;
        F.pop();

        for(int i=4; i--;)
        {
            int nx=x+dx[i], ny=y+dy[i];
            if(nx<=0 || nx>n || ny<=0 || ny>m || arr[nx][ny]=='#') continue;
            arr[nx][ny]='#';
            F.push({nx, ny});
        }
    }
}

bool jihoon()
{
    int size=J.size();
    if(size==0)
    {
        cout<<"IMPOSSIBLE";
        exit(0);
    }
    while(size--)
    {
        int x=J.front().x, y=J.front().y;
        J.pop();

        if(x==1 || x==n || y==1 || y==m) return true;
        for(int i=4; i--;)
        {
            int nx=x+dx[i], ny=y+dy[i];
            if(nx<=0 || nx>n || ny<=0 || ny>m || arr[nx][ny]=='#') continue;
            arr[nx][ny]='#';
            J.push({nx, ny});
        }
    }

    return false;
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
            if(arr[i][j]=='J')
            {
                J.push({i, j});
                arr[i][j]='#';
            }

            else if(arr[i][j]=='F')
            {
                F.push({i, j});
                arr[i][j]='#';
            }
        }
    }

    int ans=0;
    do
    {
        fire();
        ans++;
    } while(!jihoon());

    cout<<ans;
}