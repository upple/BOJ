#include<cstdio>
#include<deque>
using namespace std;

int main()
{
	deque<int> d1, d0;
	int n;
	scanf("%d", &n);
	d1.push_back(1), d1.push_back(1);
	d0.push_back(0), d0.push_back(1);
	for (int i = 2; i < n; i++)
	{
		d1.push_back(d0[1]+d1[1]%15746), d0.push_back((d1[0] + d0[0])%15746);
		d0.pop_front(), d1.pop_front();
	}

	printf("%d", (d1.back() + d0.back()) % 15746);
}