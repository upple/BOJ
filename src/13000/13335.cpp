#include <cstdio>
#include <queue>
using namespace std;

int main()
{
	queue<int> run, wait;

	int n, w, L, num, ans=0;
	scanf("%d %d %d", &n, &w, &L);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		wait.push(num);
	}

	int curL = 0;
	while (run.size() < w)
		run.push(0);

	while (run.size())
	{
		ans++;
		curL -= run.front();
		run.pop();

		if (wait.empty())
			continue;

		if (curL + wait.front() > L)
			run.push(0);

		else
		{
			curL += wait.front();
			run.push(wait.front());
			wait.pop();
		}
	}

	printf("%d", ans);
}