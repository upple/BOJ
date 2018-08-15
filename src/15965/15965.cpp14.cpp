#include <cstdio>
#include <vector>
bool arr[100000001];
std::vector<int> P;
int main()
{
	for (int i = 2; i <= 10000000; i++)
	{
		if (!arr[i])
		{
			int tmp = i;
			P.push_back(i);
			while ((tmp += i) <= 10000000)
			{
				arr[tmp] = 1;
			}
		}
	}

	int a;
	scanf("%d", &a);
	printf("%d", P[a - 1]);
}