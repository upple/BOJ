#include <cstdio>
#include <queue>
using namespace std;

struct xyz{int x, y, z;};
int dx[]={1, -1, 0, 0, 0, 0};
int dy[]={0, 0, 1, -1, 0, 0};
int dz[]={0, 0, 0, 0, 1, -1};
int cnt, r;
int n, m, h, ans;
int box[102][102][102];
int main()
{
	queue<xyz> Q;
	scanf("%d %d %d", &m, &n, &h);
	
	for(int i=1; i<=h; i++)
	{
		for(int j=1; j<=n; j++)
		{
			for(int k=1; k<=m; k++)
			{
				scanf("%d", &box[i][j][k]);
				if(box[i][j][k]!=-1) cnt++;
				if((box[i][j][k]++)==1) r++, Q.push({j, k, i});
			}
		}
	}
	
	if(cnt==r)
	{
		puts("0");
		return 0;
	}
	
	while(Q.size())
	{
		if(r==cnt)
		{
			printf("%d", ans);
			return 0;
		}
		int size=Q.size();
		while(size--)
		{
			int x=Q.front().x, y=Q.front().y, z=Q.front().z;
			Q.pop();
			for(int i=0; i<6; i++)
			{
				int nx=x+dx[i], ny=y+dy[i], nz=z+dz[i];
				if(box[nz][nx][ny]==1)
				{
					Q.push({nx, ny, nz}), box[nz][nx][ny]=2, r++;
				}
			}
		}
		ans++;
	}
	
	puts("-1");
}