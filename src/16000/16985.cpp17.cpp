#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
struct xyz{int x, y, z;};
vector<vector<vector<int> > > arr(5, vector<vector<int> >(5, vector<int>(5, 0)));
vector<vector<int> > tmp(5, vector<int>(5, 0));
const int dx[]={0, 0, 1, -1, 0, 0};
const int dy[]={1, -1, 0, 0, 0, 0};
const int dz[]={0, 0, 0, 0, 1, -1};
bool v[5][5][5];
int ans=1e9;

void solve()
{
    queue<xyz> Q;
    memset(v, 0, sizeof(v));
    v[0][0][0]=1;
    Q.push({0, 0, 0});
    int ret=0;
    while(Q.size())
    {
        for(int size=Q.size(); size--;)
        {
            int x=Q.front().x, y=Q.front().y, z=Q.front().z;
            Q.pop();
            if(x==4 && y==4 && z==4)
            {
                ans=min(ans, ret);
                return;
            }
            for(int i=0; i<6; i++)
            {
                int nx=x+dx[i], ny=y+dy[i], nz=z+dz[i];
                if(nx<0 || nx>4 || ny<0 || ny>4 || nz<0 || nz>4 || v[nx][ny][nz] || arr[nx][ny][nz]==0) continue;
                Q.push({nx, ny, nz});
                v[nx][ny][nz]=1;
            }
        }

        ret++;

    }

}

void turn(int p)
{
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            tmp[j][4-i]=arr[p][i][j];
        }
    }

    swap(tmp, arr[p]);
}
int main()
{
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            for(int k=0; k<5; k++)
                cin>>arr[i][j][k];
        }
    }

    sort(arr.begin(), arr.end());
    do
    {
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                for(int k=0; k<4; k++)
                {
                    for(int l=0; l<4; l++)
                    {
                        for(int m=0; m<4; m++)
                        {
                            if(arr[0][0][0]==0) continue;
                            solve();
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
        
    } while (next_permutation(arr.begin(), arr.end()));
    
    cout<<(ans==1e9?-1:ans);
}