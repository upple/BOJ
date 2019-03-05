#include <bits/stdc++.h>
using namespace std;

int u[10][10];
int G[3][20];
int po[3];
bool chk[10];
int n, k;
int cnt[3];

bool solve(int a, int b, int p)
{
    if(p==20) return false;
    if(a>b) swap(a, b);
    if(a==0)
    {
        for(int i=1; i<=n; i++)
        {
            if(chk[i]) continue;
            if(u[i][G[b][po[b]]]==2)
            {
                if(++cnt[0]==k) return true;
                chk[i]=1;
                po[b]++;
                if(solve(0, 3-(a+b), p+1)) return true;
                chk[i]=0;                
                cnt[0]--;
                po[b]--;
            }
            else
            {
                if(cnt[b]+1==k) continue;
                po[b]++;
                chk[i]=1;
                cnt[b]++;
                if(solve(b, 3-(a+b), p+1)) return true;
                cnt[b]--;
                chk[i]=0;
                po[b]--;
            }

        }
    }
    else
    {
        if(u[G[1][po[1]]][G[2][po[2]]]==2)
        {
            if(cnt[1]+1==k) return false;
            po[1]++;
            po[2]++;
            cnt[1]++;
            if(solve(0, 1, p+1)) return true;
            cnt[1]--;
            po[1]--;
            po[2]--;
        }
        else
        {
            if(cnt[2]+1==k) return false;
            cnt[2]++;
            po[1]++;
            po[2]++;
            if(solve(0, 2, p+1)) return true;
            cnt[2]--;
            po[1]--;
            po[2]--;
        }
    }

    return false;
}
int main()
{
    cin>>n>>k;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin>>u[i][j];
        }
    }

    for(int i=0; i<20; i++)
    {
        cin>>G[1][i];
    }

    for(int i=0; i<20; i++)
    {
        cin>>G[2][i];
    }

    cout<<solve(0, 1, 0);
}
