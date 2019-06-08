#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, num;
		priority_queue<int> l, r;
		vector<int> ans;
		scanf("%d", &n);

		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &num);
			r.size() < l.size() ? r.push(-num) : l.push(num);
			if (l.size() && r.size() && l.top()>-r.top())
			{
				int a = -l.top(), b = -r.top();
				l.pop(), r.pop();
				r.push(a), l.push(b);
			}

			if (i % 2)
				ans.push_back(l.top());
		}

		printf("%d", ans.size());
		for (int i = 0; i < ans.size(); i++)
		{
			if (!(i % 10))
				putchar('\n');

			printf("%d ", ans[i]);
		}

		printf("\n");
	}
}