#include <bits/stdc++.h>
using namespace std;

char arr[52][52];
bool v[1<<6][52][52];
struct xy{int x, y, d;};
const int dx[]={0, 0, 1, -1};
const int dy[]={1, -1, 0, 0};
int main()
{
    int n, m;
    int ex, ey;
    cin>>n>>m;
    queue<xy> Q;
    for(int i=1; i<=n; i++)
    {
        cin>>arr[i]+1;
        for(int j=1; j<=m; j++)
        {
            if(arr[i][j]=='0')
            {
                Q.push({i, j, 0});
                v[0][i][j]=1;
                arr[i][j]='.';
            }
        }
    }

    int cnt=0;
    while(Q.size())
    {
        for(int size=Q.size(); size--;)
        {
            auto [x, y, d]=Q.front();
            Q.pop();
            
            if(arr[x][y]=='1')
            {
                cout<<cnt;
                return 0;
            }

            for(int i=4; i--;)
            {
                int nx=x+dx[i], ny=y+dy[i], nd=d;
                if(!arr[nx][ny] || arr[nx][ny]=='#') continue;
                if(islower(arr[nx][ny]))
                {
                    nd |= (1<<arr[nx][ny]-'a');
                }
                if((isupper(arr[nx][ny]) && (nd & (1<<arr[nx][ny]-'A'))) || !isupper(arr[nx][ny]))
                {
                    if(!v[nd][nx][ny])
                    {
                        Q.push({nx, ny, nd});
                        v[nd][nx][ny]=1;
                    }
                }
                
            }
        }

        cnt++;
    }

    cout<<-1;
}