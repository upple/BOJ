#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int n, m, k;
struct xy{int x, y, d;};
const int dx[]={0, 0, 1, -1};
const int dy[]={1, -1, 0, 0};

char arr[1002][1002];
bool v[11][1002][1002];

int bfs()
{
    queue<xy> Q;
    Q.push({1, 1, 0});
    v[0][1][1]=1;
    int cnt=0;
    while(Q.size())
    {
        int size=Q.size();
        while(size--)
        {
            int x=Q.front().x, y=Q.front().y, d=Q.front().d;
            Q.pop();

            if(x==n && y==m) return cnt+1;

            for(int i=4; i--;)
            {
                int nx=x+dx[i], ny=y+dy[i];
                if(arr[nx][ny]=='0' && !v[d][nx][ny])
                {
                    Q.push({nx, ny, d});
                    v[d][nx][ny]=1;
                }

                else if(d<k && arr[nx][ny]=='1' && cnt%2==0 && !v[d+1][nx][ny])
                {
                    Q.push({nx, ny, d+1});
                    v[d+1][nx][ny]=1;
                }
            }

            if(cnt%2==1) Q.push({x, y, d});
        }
        cnt++;
    }

    return -1;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m>>k;
	for(int i=1; i<=n; i++)
		cin>>arr[i]+1;

	cout<<bfs();
}