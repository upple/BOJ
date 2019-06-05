#include <bits/stdc++.h>
using namespace std;

const int dx[]={0, 1, 0, -1};
const int dy[]={1, 0, -1, 0};
map<int, map<int, vector<int> > > M[2];
char a[102][102], c[11111];
int p[102][102];
int n, m, o;

void dfs(int x, int y, char color)
{
    p[x][y]=o;
    for(int i=4; i--;)
    {
        int nx=x+dx[i], ny=y+dy[i];
        if(!p[nx][ny] && a[nx][ny]==color) dfs(nx, ny, color);
    }
}

int func(int party, int dp, int cc)
{
    int x, y;
    auto &U=M[dp%2][party];

    if(dp/2==0) y=(--U.end())->first;
    else y=U.begin()->first;

    x=(((dp==1 || dp==2)+cc)%2?U[y].front():U[y].back());

    if(dp%2) swap(x, y);
    return p[x+dx[dp]][y+dy[dp]];
}

bool valid(int party)
{
    return c[party]!='X' && party;
}

int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>a[i]+1;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(p[i][j]==0) 
            {
                o++;
                dfs(i, j, a[i][j]);
                c[o]=a[i][j];
            }
            M[0][p[i][j]][j].push_back(i);
            M[1][p[i][j]][i].push_back(j);

        }
    }

    int dp=0, cc=1;
    int party=p[1][1], new_party;
    while(1)
    {
        cout<<c[party];
        bool chk=false;
        for(int i=8; i--;)
        {
            new_party=func(party, dp, cc);
            if(valid(new_party))
            {
                chk=true;
                break;
            }

            if(i%2)cc=!cc;
            else dp=(dp+1)%4;
        }

        if(!chk) break;
        party=new_party;
    }
}