#include <bits/stdc++.h>
using namespace std;

bool v[50][50];
char arr[50][51];
int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};
struct edge 
{
    int cost, to, from; 
};

inline bool operator < (const edge a, const edge b)
{
    return a.cost>b.cost;
}

int p[2500];

int Find(int a)
{
    if(p[a]==a) return a;
    return p[a]=Find(p[a]);
}

bool Union(edge &e)
{
    int pa=Find(e.to);
    int pb=Find(e.from);
    if(pa==pb) return false;
    if(pa>pb) swap(pa, pb);
    p[pb]=pa;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    priority_queue<edge> pq;
    queue<pair<int, int> > Q;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        for(int j=0; j<n; j++)
        {
            if(arr[i][j]=='S' || arr[i][j]=='K')
            {
                arr[i][j]='K';
                p[i*n+j]=i*n+j;
                Q.push({i, j});
            }
        }
            
    }

    while(Q.size())
    {
        queue<pair<int, int> > Q2;
        int sx=Q.front().first, sy=Q.front().second;
        memset(v, 0, 50*50);
        Q2.push({sx, sy});
        v[sx][sy]=1;
        Q.pop();
        int cnt=0;
        while(Q2.size())
        {
            int size=Q2.size();
            while(size--)
            {
                int x=Q2.front().first, y=Q2.front().second;
                Q2.pop();
                if(!(x==sx && y==sy) && arr[x][y]=='K')
                {
                    pq.push({cnt, sx*n+sy, x*n+y});
                    continue;
                }
                for(int i=4; i--;)
                {
                    int nx=x+dx[i], ny=y+dy[i];
                    if(nx<0 || nx>=n || ny<0 || ny>=n || v[nx][ny] || arr[nx][ny]=='1') continue;
                    v[nx][ny]=1;
                    Q2.push({nx, ny});
                }
            }
            
            cnt++;
        }

    }

    int ans=0;
    while(m)
    {
        if(pq.empty())
        {
            cout<<-1;
            return 0;
        }
        edge cur=pq.top();
        pq.pop();
        if(Union(cur))
        {
            ans+=cur.cost;
            m--;
        }
    }

    cout<<ans;
}