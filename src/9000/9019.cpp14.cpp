#include <cstdio>
#include <queue>
using namespace std;
int a, b;
char DSLR[]={'D', 'S', 'L', 'R'};

struct CN
{
	char c;
	int n;
};
void printRoute(int x, CN past[])
{
	if(a!=past[x].n)
		printRoute(past[x].n, past);

	printf("%c", past[x].c);
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		CN past[10000]={};
		queue<int> Q;
		scanf("%d %d", &a, &b);

		Q.push(a);
		while(Q.size())
		{
			int cur=Q.front();
			Q.pop();

			if(cur==b)
			{
				printRoute(b, past);
				printf("\n");
				break;
			}

			int arr[]={(cur*2)%10000, (cur+9999)%10000, cur%1000*10+cur/1000, cur%10*1000+cur/10};

			for(int i=0; i<4; i++)
			{
				if(!past[arr[i]].c)
					past[arr[i]]={DSLR[i], cur}, Q.push(arr[i]);
			}
		}
	}
}
