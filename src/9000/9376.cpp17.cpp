#include <bits/stdc++.h>
#define INF 1e8
using namespace std;
struct xy{int x, y;};

int h, w;
int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};
bool inQ[102][102];
vector<vector<char> > arr;
vector<vector<int> > dist, res;

void spfa(xy &p)
{
    queue<xy> Q;
    dist.assign(h+2, vector<int>(w+2, INF));
    dist[p.x][p.y]=0;
    Q.push({p.x, p.y});
    while(Q.size())
    {
        int x=Q.front().x, y=Q.front().y;
        Q.pop();
        inQ[x][y]=0;
        for(int i=4; i--;)
        {
            int nx=x+dx[i], ny=y+dy[i];
            if(nx<0 || nx>h+1 || ny<0 || ny>w+1|| arr[nx][ny]=='*') continue;
            if(dist[nx][ny]>dist[x][y]+(arr[nx][ny]=='#'))
            {
                dist[nx][ny]=dist[x][y]+(arr[nx][ny]=='#');
                if(!inQ[nx][ny]) inQ[nx][ny]=1, Q.push({nx, ny});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>h>>w;
        arr.assign(h+2, vector<char>(w+2, '.'));
        res.assign(h+2, vector<int>(w+2, 0));
        vector<xy> pos;
        for(int i=1; i<=h; i++)
        {    
            for(int j=1; j<=w; j++)
            {
                cin>>arr[i][j];
                if(arr[i][j]=='$') pos.push_back({i, j});
            }
            cin.get();  
        }

        pos.push_back({0, 0});
        
        for(int i=0; i<pos.size(); i++)
        {
            spfa(pos[i]);
            for(int j=0; j<=h+1; j++)
                for(int k=0; k<=w+1; k++)
                    res[j][k]+=dist[j][k];
        }

        int ans=INF;
        for(int i=0; i<=h+1; i++)
            for(int j=0; j<=w+1; j++)
                ans=min(ans, res[i][j]-2*(arr[i][j]=='#'));

        cout<<ans<<"\n";
    }

}