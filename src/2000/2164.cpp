#include <cstdio>
#include <queue>
using namespace std;
int main()
{
	int n;
	queue<int> Q;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		Q.push(i);

	while (Q.size() != 1)
	{
		Q.pop();
		Q.push(Q.front());
		Q.pop();
	}

	printf("%d", Q.front());
}