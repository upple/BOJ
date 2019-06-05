#include <cstdio>
#include <vector>
#include <deque>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		vector<int> arr(n + 1);
		vector<bool> visit(n + 1, 0);
		int ans = n;
		for (int i = 1; i <= n; i++)
			scanf("%d", &arr[i]);

		for (int i = 1; i <= n; i++)
		{
			if (!visit[i])
			{
				deque<int> dq;
				int pos = i;
				do
				{
					dq.push_back(pos);
					visit[pos] = true;
					pos = arr[pos];
				} while (!visit[pos]);

				while (!dq.empty() && dq.front() != pos)
					dq.pop_front();

				ans -= dq.size();
					
			}
		}

		printf("%d\n", ans);
	}
}