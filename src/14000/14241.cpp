#include <cstdio>
#include <queue>
using namespace std;

priority_queue<int> pq;
int main()
{
	int n, ans=0;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		int k;
		scanf("%d", &k);
		pq.push(k);

	}

	while(pq.size()>1)
	{
		int a=pq.top(); pq.pop();
		int b=pq.top(); pq.pop();
		pq.push(a+b);
		ans+=a*b;
	}

	printf("%d", ans);
}
