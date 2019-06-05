#include <bits/stdc++.h>
using namespace std;

int s[12][12], arr[12][12], death[12][12], prop[12][12];
map<int, long long> tree[12][12];
int dx[]={0, 1, 1, 1, 0, -1, -1, -1};
int dy[]={1, 1, 0, -1, -1, -1, 0, 1};

int n, m, k;

void spring()
{
	queue<int> tmp;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			map<int, long long> tmp;
			for(auto &u : tree[i][j])
			{
				int it=u.first, cnt=u.second;
				int remain=min(arr[i][j]/it, cnt);
				death[i][j]+=it/2*(cnt-remain);

				if(remain==0) continue;
				arr[i][j]-=it*remain;
				tmp[it+1]+=remain;
				if((it+1)%5==0) prop[i][j]+=remain;
			}
			
			swap(tree[i][j], tmp);
			tmp.clear();
		}
	}
}

void summer()
{
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			arr[i][j]+=death[i][j];
			death[i][j]=0;
		}
	}
}

void fall()
{
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			for(int k=8; k--;)
			{
				int nx=i+dx[k], ny=j+dy[k];
				tree[nx][ny][1]+=prop[i][j];
			}

			prop[i][j]=0;
		}
	}
}

void winter()
{
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			arr[i][j]+=s[i][j];
		}
	}
}

long long cnt_tree()
{
	long long ret=0;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			for(auto &u : tree[i][j])
			{
				ret+=u.second;
			}
		}
	}

	return ret;
}
int main()
{
	cin>>n>>m>>k;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			cin>>s[i][j];
			arr[i][j]=5;
		}
	}

	while(m--)
	{
		int x, y, a;
		cin>>x>>y>>a;
		tree[x][y][a]++;
	}

	while(k--)
	{
		spring();
		summer();
		fall();
		winter();
	}
	
	cout<<cnt_tree();
}