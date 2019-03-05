#include <bits/stdc++.h>
using namespace std;

const int dx[]={-2, -2, 0, 0, 2, 2};
const int dy[]={-1, 1, -2, 2, -1, 1};
int v[201][201];
int main()
{
    int n;
    cin>>n;
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    queue<pair<int, int> > Q;
    Q.push({a, b});
    v[a][b]=1;
    while(Q.size())
    {
        int x=Q.front().first, y=Q.front().second;
        Q.pop();
        if(x==c && y==d)
        {
            cout<<v[c][d]-1;
            return 0;
        }

        for(int i=6; i--;)
        {
            int nx=x+dx[i], ny=y+dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=n || v[nx][ny]) continue;
            v[nx][ny]=v[x][y]+1;
            Q.push({nx, ny});
        }
    }

    cout<<-1;
}