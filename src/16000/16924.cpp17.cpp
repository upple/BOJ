#include <bits/stdc++.h>
using namespace std;

const int dx[]={0, 0, 1, -1};
const int dy[]={1, -1, 0, 0};
struct xy{int x, y;};
vector<xy> target, ans;
vector<int> s;
int n, m;
char arr[102][102];
bool v[102][102];
int remain;
int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>arr[i]+1;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            bool chk=true;
            if(arr[i][j]!='*') continue;
            remain++;

            for(int k=4; k--;)
            {
                int nx=i+dx[k], ny=j+dy[k];
                if(arr[nx][ny]!='*')
                {
                    chk=false;
                    break;
                }
            }

            if(chk==true)
            {
                target.push_back({i, j});
            }
        }
    }

    for(xy &cur : target)
    {
        int x=cur.x, y=cur.y;
        int _min=1e9, _max=0;
        for(int k=4; k--;)
        {
            int nx=x, ny=y;
            int cnt=0, local=0;
            while(arr[nx+=dx[k]][ny+=dy[k]]=='*')
            {
                cnt++;
                if(v[nx][ny]==0) local=cnt;
            }
            _max=max(_max, local);
            _min=min(_min, cnt);
        }
        
        if(min(_min, _max)==0 && v[x][y]==0)
        {
            ans.push_back({x, y});
            v[x][y]=1;
            remain--;
            s.push_back(1);
        }
        else if(min(_min, _max)>0)
        {
            ans.push_back({x, y});
            s.push_back(min(_min, _max));
            
            if(v[x][y]==0)
            {
                v[x][y]=1;
                remain--;
            }
            for(int k=4; k--;)
            {
                int nx=x, ny=y;
                for(int u=1; u<=min(_min, _max); u++)
                {
                    nx+=dx[k], ny+=dy[k];
                    if(v[nx][ny]==0)
                    {
                        v[nx][ny]=1;
                        remain--;
                    }   
                }
            }

        }

        if(remain==0) break;
    }

    if(remain>0)
    {
        cout<<-1;
        return 0;
    }
    cout<<ans.size()<<'\n';
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i].x<<' '<<ans[i].y<<' '<<s[i]<<'\n';
    }
}