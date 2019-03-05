#include<cstdio>
#include<queue>
#include<functional>

using namespace std;
int main()
{
	int n, k, num;
	priority_queue<int, vector<int>, greater<int> > Q;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		Q.push(num);
	}

	while (--k)
		Q.pop();

	printf("%d\n", Q.top());
}