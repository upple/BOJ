#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
const int dx[]={0, 0, 1, -1};
const int dy[]={1, -1, 0, 0};

int n, l, r;
int arr[52][52];
int visit[52][52];

pair<int, int> dfs(int x, int y)
// 해당칸이 포함된 연합의 크기와 인구수를 리턴하는
// 함수
{
    visit[x][y]=1;
    pair<int, int> ret={1, arr[x][y]};

    for(int i=4; i--;)
    {
        int nx=x+dx[i], ny=y+dy[i];
        if(arr[nx][ny]==0 || visit[nx][ny]!=0) continue;
        if(abs(arr[x][y]-arr[nx][ny])<l || abs(arr[x][y]-arr[nx][ny])>r) continue;
        auto tmp=dfs(nx, ny);
        ret.first+=tmp.first;
        ret.second+=tmp.second;
    }

    return ret;
}

void move(int x, int y, int val)
// 해당칸이 속한 연합을 새로운 인구수로 갱신해주는 함수
{
    visit[x][y]=2;
    arr[x][y]=val;
    for(int i=4; i--;)
    {
        int nx=x+dx[i], ny=y+dy[i];
        if(visit[nx][ny]==1)
        {
            move(nx, ny, val);
        }
    }
}
int main()
{
    cin>>n>>l>>r;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin>>arr[i][j];
        }
    }

    int cnt=0;
    while(1)
    {
        bool chk=false;
        memset(visit, 0, sizeof(visit));
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(visit[i][j]!=0) continue;
                auto ret=dfs(i, j);
                if(ret.first>1)
                // 해당 칸이 포함된 연합의 개수가
                // 1개보다 큰 경우
                {
                    chk=true;
                }

                move(i, j, ret.second/ret.first);
            }
        }

        if(chk==false) break;
        cnt++;
    }

    cout<<cnt;
}