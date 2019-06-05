#include <bits/stdc++.h>
using namespace std;
const int dx[]={0, 0, 1, -1, -1, 1, 1, -1};
const int dy[]={1, -1, 0, 0, 1, 1, -1, -1};

char arr[10][10];
bool v[10][10];
queue<int> Q, b;
bool bfs()
{
    for(int t=Q.size(); t--;)
    {
        int x=Q.front()>>4, y=Q.front()&0xf;
        Q.pop();
        if(x==1 && y==8) return true;
        if(arr[x][y]=='#') continue;
        for(int i=8; i--;)
        {
            int nx=x+dx[i], ny=y+dy[i];
            if(arr[nx][ny]!='.' || v[nx][ny]) continue;
            Q.push((nx<<4)+ny);
            v[nx][ny]=1;
        }

        Q.push((x<<4)+y);
    }
    return false;
}

void fall()
{
    for(int i=1; i<=8; i++)
    {
        for(int j=1; j<=8; j++)
        {
            arr[i][j]='.';
        }
    }

    for(int t=b.size(); t--;)
    {
        int x=b.front()>>4, y=b.front()&0xf;
        b.pop();
        v[x][y]=0;
        if(arr[x+1][y]=='.') arr[x+1][y]='#', b.push(((x+1)<<4)+y);
    }

}
int main()
{
    for(int i=1; i<=8; i++)
    {
        cin>>arr[i]+1;
        for(int j=1; j<=8; j++)
        {
            if(arr[i][j]=='#') b.push((i<<4)+j);
        }
    }

    Q.push(129);
    v[8][1]=1;

    while(1)
    {   
        if(bfs())
        {
            cout<<1;
            return 0;
        }
        if(Q.empty())
        {
            cout<<0;
            return 0;
        }
        fall();
    }
}