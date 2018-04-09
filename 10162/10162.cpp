#include<cstdio>
#include<queue>
using namespace std;
class ABC
{
public:
	int time, A, B, C;
	ABC(int t, int a=0, int b=0, int c=0) :time(t), A(a), B(b), C(c) {}
};
int main()
{
	int n, ans=1;
	bool M[10001] = {};
	queue<ABC> Q;
	scanf("%d", &n);
	if (n % 10)
	{
		printf("-1\n");
		return 0;
	}
	Q.push(ABC(300, 1)), Q.push(ABC(60, 0, 1)), Q.push(ABC(10, 0, 0, 1));
	while (!Q.empty())
	{
		ABC pos = Q.front();
		Q.pop();
		
		if (pos.time == n)
		{
			printf("%d %d %d\n", pos.A, pos.B, pos.C);
			return 0;
		}

		if (pos.time > n || M[pos.time])
			continue;

		Q.push(ABC(pos.time + 300, pos.A + 1, pos.B, pos.C));
		Q.push(ABC(pos.time + 60, pos.A, pos.B + 1, pos.C));
		Q.push(ABC(pos.time + 10, pos.A, pos.B, pos.C + 1));
		M[pos.time] = true;

	}
	printf("-1\n");
}