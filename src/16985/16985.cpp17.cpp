#include <bits/stdc++.h>
using namespace std;

int (*cube[5])[5];
int arr[5][5][5];
bool v[5][5][5];
const int dx[]={0, 0, 1, -1, 0, 0};
const int dy[]={1, -1, 0, 0, 0, 0};
const int dz[]={0, 0, 0, 0, 1, -1};
int tmp[5][5];
int ans=1e9;
int bfs()
{
    queue<int> Q;
    memset(v, 0, sizeof(v));
    Q.push(0);
    v[0][0][0]=1;
    if(cube[0][0][0]==0 || cube[4][4][4]==0) return -1;
    int cnt=0;
    while(Q.size())
    {
        if(cnt==ans) return -1;
        for(int size=Q.size(); size--;)
        {
            int x=Q.front()/100, y=Q.front()%100/10, z=Q.front()%10;
            Q.pop();

            if(x==4 && y==4 && z==4) return cnt;
            for(int i=6; i--;)
            {
                int nx=x+dx[i], ny=y+dy[i], nz=z+dz[i];
                if(nx<0 || nx>=5 || ny<0 || ny>=5 || nz<0 || nz>=5 || cube[nx][ny][nz]==0 || v[nx][ny][nz]) continue;
                Q.push(nx*100+ny*10+nz);
                v[nx][ny][nz]=1;
            }
        }

        cnt++;
    }

    return -1;
}

void turn(int p)
{
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            tmp[4-j][i]=cube[p][i][j];
        }
    }

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            cube[p][i][j]=tmp[i][j];
        }
    }
}
int main()
{
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            for(int k=0; k<5; k++)
            {
                cin>>arr[i][j][k];
            }
        }

        cube[i]=arr[i];
    }

    do
    {
        for(int i=0; i<4; i++)
        {
            if(cube[0][0][0]==0)
            {
                turn(0);
                continue;
            }
            for(int j=0; j<4; j++)
            {
                for(int k=0; k<4; k++)
                {
                    for(int l=0; l<4; l++)
                    {
                        for(int m=0; m<4; m++)
                        {
                            int ret=bfs();
                            if(ret!=-1) ans=min(ans, ret);
                            turn(4);
                        }
                        turn(3);
                    }
                    turn(2);
                }
                turn(1);
            }
            turn(0);
        }
    } while(next_permutation(cube, cube+5));
    

    cout<<(ans==1e9?-1:ans);
}