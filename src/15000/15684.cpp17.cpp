#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, h, m;
int chk[31][12];

bool solve(int c, int x, int y, vector<int> v)
{
    for(int i=x; i<=h; i++)
    {
        for(int j=y; j<n; j++)
        {
            if(chk[i][j]==1) swap(v[j], v[j+1]);
            if(c==0 || chk[i][j-1]==1 || chk[i][j]==1 || chk[i][j+1]==1) continue;
            chk[i][j]=1;
            swap(v[j], v[j+1]);
            if(solve(c-1, i, j+2, v))
            {
                return true;
            }
            swap(v[j], v[j+1]);
            chk[i][j]=0;
        }

        y=1;
    }

    for(int i=1; i<=n; i++)
    {
        if(v[i]!=i) return false;
    }

    return true;
}
int main()
{
    cin>>n>>m>>h;

    while(m--)
    {
        int a, b;
        cin>>a>>b;
        chk[a][b]=1;
    }

    vector<int> res(n+1);
    for(int i=1; i<=n; i++)
        res[i]=i;

    for(int i=0; i<=3; i++)
    {
        if(solve(i, 1, 1, res))
        {
            cout<<i;
            return 0;
        }
    }

    cout<<-1;
}
