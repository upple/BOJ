#include <bits/stdc++.h>
using namespace std;

struct xy{int x, y;};
const int dx[]={0, 0, 1, -1};
const int dy[]={1, -1, 0, 0};

char arr[12][12];
int u[12][12];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    int lx=1e9, rx=0, ly=1e9, ry=0;
    cin>>r>>c;

    for(int i=1; i<=r; i++)
        cin>>arr[i]+1;

    for(int i=1; i<=r; i++)
    {
        for(int j=1; j<=c; j++)
        {
            if(arr[i][j]=='X')
            {
                for(int k=4; k--;)
                {
                    int nx=i+dx[k], ny=j+dy[k];
                    if(arr[nx][ny]!='X') u[i][j]++;
                }
                if(u[i][j]<3)
                {
                    lx=min(lx, i);
                    ly=min(ly, j);
                    rx=max(rx, i);
                    ry=max(ry, j);
                }
            }

        }
    }

    for(int i=lx; i<=rx; i++)
    {
        for(int j=ly; j<=ry; j++)
        {
            cout<<((u[i][j]>=3||arr[i][j]=='.')?'.':'X');
        }
        cout<<'\n';
    }

}