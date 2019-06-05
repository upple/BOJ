#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct xy{int x, y;};
const int dx[]={0, 1, 0, -1};
const int dy[]={1, 0, -1, 0};
int remain, ans=1e9;

vector<xy> cam;
int arr[8][8];
bool chk[8][8];
int n, m;

int solve(int c)
{
    if(c==cam.size()) return remain;
    vector<int> dir;
    int x=cam[c].x, y=cam[c].y;
    switch(arr[x][y])
    {
        case 1:
        dir={0}; break;
        case 2:
        dir={0, 2}; break;
        case 3:
        dir={0, 3}; break;
        case 4:
        dir={0, 2, 3}; break;
        case 5:
        dir={0, 1, 2, 3}; break;
    }

    for(int i=4; i--;)
    {
        queue<xy> Q;
        for(int d : dir)
        {
            int nx=x+dx[(d+i)%4], ny=y+dy[(d+i)%4];
            while(nx>=0 && nx<n && ny>=0 && ny<m && arr[nx][ny]!=6)
            {
                if(chk[nx][ny]==0 && arr[nx][ny]==0)
                {
                    chk[nx][ny]=1;
                    remain--;
                    Q.push({nx, ny});
                }

                nx+=dx[(d+i)%4], ny+=dy[(d+i)%4];
            }
        }

        ans=min(ans, solve(c+1));
        while(Q.size())
        {
            int x=Q.front().x, y=Q.front().y;
            Q.pop();

            chk[x][y]=0;
            remain++;
        }
    }

    return ans;
}

int main()
{
    cin>>n>>m;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]==0) remain++;
            if(arr[i][j]!=0 && arr[i][j]!=6)
            {
                cam.push_back({i, j});
            }
        }

    }

    cout<<solve(0);
}