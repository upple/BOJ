#include <bits/stdc++.h>
using namespace std;
const int dx[]={0, 0, 1, -1};
const int dy[]={1, -1, 0, 0};
char arr[1002][1002];
int v[1002][1002];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, k;
    cin>>n>>m>>k;

    for(int i=1; i<=n; i++)
    {
        cin>>arr[i]+1;
    }

    int sx, sy, ex, ey;
    cin>>sx>>sy>>ex>>ey;

    queue<int> Q;
    Q.push((sx<<10)+sy);
	v[sx][sy]=1;
    int cnt=0;
    while(Q.size())
    {
        int size=Q.size();
        while(size--)
        {
            int x=Q.front()>>10, y=Q.front()&0x3ff;
            Q.pop();
            if(x==ex && y==ey) 
            {
                cout<<v[ex][ey]-1;
                return 0;
            }

            for(int i=4; i--;)
            {
                int nx=x, ny=y;
                for(int j=0; j<k; j++)
                {
                    nx+=dx[i], ny+=dy[i];
                    if(arr[nx][ny]!='.' || (v[nx][ny] && v[nx][ny]<=v[x][y])) break;
					if(v[nx][ny]) continue;
                    Q.push((nx<<10)+ny);
                    v[nx][ny]=v[x][y]+1;
                }
            }
        }
    }

    cout<<-1;
}