#include<cstdio>
#include<queue>
using namespace std;

int main()
{
	int n, num;
	priority_queue<int, vector<int>, greater<int> > Queue;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		Queue.push(num);
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d ", Queue.top());
		Queue.pop();
	}
	
	return 0;
}