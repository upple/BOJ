#include <cstdio>
#include <queue>
using namespace std;

int main()
{
	priority_queue<int, vector<int>, greater<int> > Queue;
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		int num;
		scanf("%d", &num);
		if(num==0)
		{
			if(Queue.empty())
				printf("0\n");

			else
				printf("%d\n", Queue.top()), Queue.pop();
		}

		else
			Queue.push(num);
	}

	return 0;
}
