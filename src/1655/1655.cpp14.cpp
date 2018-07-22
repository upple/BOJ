#include <cstdio>
#include <queue>
#include <functional>
using namespace std;

int main()
{
	int n, num;
	priority_queue<int, vector<int>, greater<int> > u;
	priority_queue<int> l;

	scanf("%d %d", &n, &num);
	printf("%d\n", num);
	l.push(num);

	while (--n)
	{
		scanf("%d", &num);
		l.size() > u.size() ? u.push(num) : l.push(num);

		int lt = l.top(), ut = u.top();

		if (lt > ut)
		{
			l.pop(), u.pop();
			l.push(ut);
			u.push(lt);
		}

		printf("%d\n", l.top());
	}
	
}