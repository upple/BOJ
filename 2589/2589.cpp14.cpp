#include<cstdio>
#include<queue>
using namespace std;

int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};
char map[50][51];
int r, c;
int bfs(int x, int y)
{
    queue<pair<int, int> > Q;
    int count=0;
    
    Q.push({x, y});
    Q.push({-1, -1});
    int v[50][51]={};
    v[x][y]=true;
    while(!Q.empty())
    {
        x=Q.front().first, y=Q.front().second;
        Q.pop();
        if(x==-1)
        {
            if(Q.empty())
                return count;

            count++, Q.push({-1, -1});
            continue;
        }
        for(int i=0; i<4; i++)
        {
            int nx=x+dx[i], ny=y+dy[i];
            if(nx>=0 && nx<r && ny>=0 && ny<c && !v[nx][ny] && map[nx][ny]=='L')
                v[nx][ny]=true, Q.push({nx, ny});
        }
    }
}
int main()
{
    int max=0;
    scanf("%d %d", &r, &c);

    for(int i=0; i<r; i++)
        scanf("%s", map[i]);

    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            if(map[i][j]=='L')
            {
                int d=bfs(i, j);
                max=max>d?max:d;
            }

    printf("%d", max);
}
