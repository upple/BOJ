#include <bits/stdc++.h>
using namespace std;
struct xy{int x, y;};
char arr[11][11], p[10][10][10][10];
pair<xy, xy> path[10][10][10][10];
bool v[10][10][10][10];
const int dx[]={0, 0, -1, 1};
const int dy[]={-1, 1, 0, 0};
const char dir[]="LRUD";
xy B, R, O, LB, LR;
int n, m;
inline bool valid(int x, int y)
{
    return (x>0 && x<n-1 && y>0 && y<m-1 && arr[x][y]=='.');
}
int bfs()
{
    queue<xy> bq, rq;
    bq.push(B);
    rq.push(R);

    v[B.x][B.y][R.x][R.y]=1;
    int cnt=0;
    while(bq.size())
    {
        for(int size=bq.size(); size--;)
        {
            int bx=bq.front().x, by=bq.front().y;
            int rx=rq.front().x, ry=rq.front().y;
            bq.pop(), rq.pop();

            for(int i=4; i--;)
            {
                int nbx=bx, nby=by;
                int nrx=rx, nry=ry;
                bool ro=false, bo=false;
                bool chk=false;
                while(1)
                {
                    if(!valid(nbx+dx[i], nby+dy[i])) break;
                    
                    nbx+=dx[i], nby+=dy[i];
                    if(O.x==nbx && O.y==nby)
                    {
                        bo=true;
                        break;
                    }
                    if(nbx==rx && nby==ry)
                    {
                        chk=true;
                    }
                }

                if(bo) continue;
                while(1)
                {
                    if(!valid(nrx+dx[i], nry+dy[i])) break;
                    
                    nrx+=dx[i], nry+=dy[i];
                    if(O.x==nrx && O.y==nry)
                    {
                        ro=true;
                        break;
                    }
                }

                if(ro) 
                {
                    p[9][9][9][9]=dir[i];
                    path[9][9][9][9]={{bx, by}, {rx, ry}};
                    return cnt+1;
                }
                
                if(nbx==nrx && nby==nry)
                {
                    if(chk)
                    {
                        nbx-=dx[i], nby-=dy[i];
                    }
                    else
                    {
                        nrx-=dx[i], nry-=dy[i];
                    }
                }

                if(v[nbx][nby][nrx][nry]) continue;
                v[nbx][nby][nrx][nry]=1;
                p[nbx][nby][nrx][nry]=dir[i];
                path[nbx][nby][nrx][nry]={{bx, by}, {rx, ry}};
                    
                bq.push({nbx, nby});
                rq.push({nrx, nry});
            }
        }

        cnt++;
        if(cnt>=10) break;
    }
    return -1;
}
int main()
{
    cin>>n>>m;

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        for(int j=1; j<m; j++)
        {
            if(arr[i][j]=='B')
            {
                B={i, j};
                arr[i][j]='.';
            }
            else if(arr[i][j]=='R')
            {
                R={i, j};
                arr[i][j]='.';
            }
            else if(arr[i][j]=='O')
            {
                O={i, j};
                arr[i][j]='.';
            }
        }
    }

    int res=bfs();
    cout<<res<<'\n';
    if(res!=-1)
    {
        string ans;
        int bx=9, by=9, rx=9, ry=9;
        while(res--)
        {
            ans.push_back(p[bx][by][rx][ry]);
            xy &a=path[bx][by][rx][ry].first;
            xy &b=path[bx][by][rx][ry].second;
            bx=a.x, by=a.y, rx=b.x, ry=b.y;
        }

        reverse(ans.begin(), ans.end());
        cout<<ans;
    }
}