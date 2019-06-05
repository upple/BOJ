#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};
int n;
int map[100][100];
bool visit[100][100]={};
vector<queue<pair<int, int> > >Q;

void dfs(int x, int y, int &c)
{
    map[x][y]=c;
    bool isEdge=false;
    for(int i=0; i<4; i++)
    {
        int nx=x+dx[i], ny=y+dy[i];
        if(nx>=0 && nx<n && ny>=0 && ny<n)
        {
            if(!visit[nx][ny] && map[nx][ny])
                visit[nx][ny]=true, dfs(nx, ny, c);

            else if(!map[nx][ny])
                isEdge=true;
        }

        if(isEdge)
            Q[c].push({x, y});
    }
}

int bfs(int c)
{
    Q[c].push({-1, -1});
    bool isEdge=false, visit[100][100]={};
    int count=0;
    while(1)
    {
        int x=Q[c].front().first, y=Q[c].front().second;
        Q[c].pop();
        if(x==-1)
        {
            count++, Q[c].push({-1, -1});
            continue;
        }

        for(int i=0; i<4; i++)
        {
            int nx=x+dx[i], ny=y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<n)
            {
                if(!visit[nx][ny] && !map[nx][ny])
                    visit[nx][ny]=true, Q[c].push({nx, ny});

                else if(map[nx][ny] && c!=map[nx][ny])
                    return count;
            }

            if(isEdge)
                Q[c].push({x, y});
        }
    }
}
int main()
{
    int color=0, ans=4444;
    scanf("%d", &n);
    Q.push_back(queue<pair<int, int> >());
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &map[i][j]);

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(map[i][j] && !visit[i][j])
                visit[i][j]=true, Q.push_back(queue<pair<int, int> >()), dfs(i, j, ++color);

    for(int i=1; i<Q.size(); i++)
    {
        int temp=bfs(i);
        ans=(ans<temp?ans:temp);
    }

    printf("%d", ans);
}
