#include <cstdio>
#include <queue>
using namespace std;

int visit[301];
int main()
{
	int h[3], n;
	queue<int> Q;
	scanf("%d %d %d %d", h, h+1, h+2, &n);

	visit[n]=1;
	Q.push(n);
	while(Q.size())
	{
		int cur=Q.front();
		Q.pop();

		for(int i=0; i<3; i++)
		{
			int next=cur-h[i];
			if(next==0)
			{
				printf("1");
				return 0;
			}
			if(next>0 && !visit[next])
			{
				Q.push(next);
				visit[next]=1;
			}
		}
	}

	printf("0");
}
