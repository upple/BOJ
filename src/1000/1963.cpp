#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;

int main()
{
	bool prime[10000]={};

	for(int i=2; i<10000; i++)
	{
		if(!prime[i])
		{
			int temp=i;
			while((temp+=i)<10000)
				prime[temp]=true;
		}
	}

	int n;
	scanf("%d", &n);

	while(n--)
	{
		int a, b, count=0;
		bool visit[10000]={};
		scanf("%d %d", &a, &b);
		queue<int> Q;
		Q.push(a), Q.push(0), visit[a]=1;
		while(Q.size())
		{
			int cur=Q.front();
			Q.pop();
			if(!cur)
			{
				if(Q.empty())
				{
					printf("Impossible\n");
					break;
				}

				Q.push(0), count++;
				continue;
			}

			if(cur==b)
			{
				printf("%d\n", count);
				break;
			}

			for(int i=0; i<4; i++)
			{
				int temp=cur-(cur%(int)pow(10, i+1)-cur%(int)pow(10, i));

				for(int j=0; j<10; j++)
				{
					int temp2=temp+j*(int)pow(10, i);
					if(temp2<1000 || visit[temp2] || prime[temp2])
						continue;

					visit[temp2]=true; Q.push(temp2);
				}
			}
		}
	}
}
