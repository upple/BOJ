#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int n, m, c=0, w=0, wc=0;
	queue<pair<int, int> > Q;
	scanf("%d %d", &n, &m);

	while(m--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		Q.push({a, b});
	}

	while(Q.size())
	{
		int a=Q.front().first, b=Q.front().second;
		if(c==n)
			wc=w, w=c=0;

		if(w<=(a=max(a, wc)))
			c=1, w=a+b;
        
		else
		{
			w=max(w, a+b);
			c++;
		}

		Q.pop();

	}

	printf("%d", c);
}
