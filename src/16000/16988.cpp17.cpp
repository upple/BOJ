#include <bits/stdc++.h>
using namespace std;

int n, m;
const int dx[]={0, 0, 1, -1};
const int dy[]={1, -1, 0, 0};
int arr[20][20];
int p[20][20], s[400], b[400];
vector<int> adj[20][20];
int set_num;
void bfs(int x, int y)
{
    queue<int> Q;
    int size=0, block=0;
    set_num++;
    Q.push((x<<5)+y);
    p[x][y]=set_num;
    while(Q.size())
    {
        int x=Q.front()>>5, y=Q.front()&0x1f;
        Q.pop();
        size++;
        for(int i=4; i--;)
        {
            int nx=x+dx[i], ny=y+dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m || arr[nx][ny]==1 || p[nx][ny]==set_num) continue;
            if(arr[nx][ny]==2)
            {
                Q.push((nx<<5)+ny);
            }

            else
            {
                block++;
                adj[nx][ny].push_back(set_num);
            }

            p[nx][ny]=set_num;
        }
    }

    s[set_num]=size, b[set_num]=block;
}

int solve(int x, int y, int r, int c)
{
    if(r==2) return c;
    int ret=c;
    for(int i=x; i<n; i++)
    {
        for(int j=y; j<m; j++)
        {
            int tmp=c;
            if(arr[i][j]==0)
            {
                for(int set_num : adj[i][j])
                {
                    b[set_num]--;
                    if(b[set_num]==0) tmp+=s[set_num];
                }
                
                ret=max(ret, solve(i, j+1, r+1, tmp));
                for(int set_num : adj[i][j])
                {
                    b[set_num]++;
                }
            }
        }
        y=0;
    }

    return ret;
}
int main()
{
    cin>>n>>m;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(arr[i][j]==2 && !p[i][j])
            {
                bfs(i, j);
            }
        }
    }

    cout<<solve(0, 0, 0, 0);
}