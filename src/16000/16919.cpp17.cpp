#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int dx[]={0, 0, 1, -1};
const int dy[]={1, -1, 0, 0};
struct xy{int x, y;};
queue<xy> Q[2];
// Q[0] : 1초지난 폭탄 목록
// Q[1] : 3초 지난 폭탄 목록
char arr[202][202];
int n, m, k;

void bfs(bool t)
{
    if(t==0)// 폭탄 심는 시간
    {
        while(Q[0].size())
        {
            int x=Q[0].front().x, y=Q[0].front().y;
            Q[0].pop();
            if(arr[x][y]=='O') Q[1].push({x, y});
        }

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(arr[i][j]=='.')
                {
                    Q[0].push({i, j});
                    arr[i][j]='O';
                }
            }
        }
    }
    else// 폭탄 터지는 시간
    {
        while(Q[1].size())
        {
            int x=Q[1].front().x, y=Q[1].front().y;
            Q[1].pop();

            arr[x][y]='.';
            for(int i=4; i--;)
            {
                int nx=x+dx[i], ny=y+dy[i];
                if(arr[nx][ny]=='O') arr[nx][ny]='.';
            }
        }
    }
    //지금 1초 때 터진거랑 3초때 터진걸
    //구분하는 방법에 대해 고민중입니다..

}
int main()
{
    cin>>n>>m>>k;

    for(int i=1; i<=n; i++)
    {
        cin>>arr[i]+1;
        for(int j=1; j<=m; j++)
        {
            if(arr[i][j]=='O')
                Q[0].push({i, j});
        }
    }

    if(k>1 && (k-1)%4==0) k=5;
    else k=(k-1)%4+1;
    for(int i=2; i<=k; i++)
    {
        bfs(i%2);
    }

    for(int i=1; i<=n; i++)
    {
        cout<<arr[i]+1<<'\n';
    }
}