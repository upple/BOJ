#include<cstdio>
using namespace std;
int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};
int n;
int map[100][100];
void dfs(bool visit[100][100], int x, int y, int d)
{
    for(int i=0; i<4; i++)
    {
        int nx=x+dx[i], ny=y+dy[i];
        if(nx>=0 && nx<n && ny>=0 && ny<n && !visit[nx][ny] && map[nx][ny]>d)
            visit[nx][ny]=true, dfs(visit, nx, ny, d);
    }
}
int main()
{
    int min=111, max=0, ans=0;
    scanf("%d", &n);

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            scanf("%d", &map[i][j]);
            min=min<map[i][j]?min:map[i][j];
            max=max>map[i][j]?max:map[i][j];
        }

    for(int i=min-1; i<max; i++)
    {
        bool visit[100][100]={};
        int count=0;
        for(int j=0; j<n; j++)
            for(int k=0; k<n; k++)
                if(!visit[j][k] && map[j][k]>i)
                    count++, visit[j][k]=true, dfs(visit, j, k, i);

        ans=ans>count?ans:count;
    }

    printf("%d", ans);
}
