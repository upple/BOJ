#include<cstdio>
#include<vector>
using namespace std;

int main()
{
	bool arr[1000001] = {};
	vector<int> prime;
	int n;
	for (int i = 2; i <= 1000000; i++)
	{
		if (!arr[i])
		{
			prime.push_back(i);
			int temp = i;
			while ((temp += i) <= 1000000)
				arr[temp] = true;

		}
	}

	while (scanf("%d", &n) && n)
	{
		for (int i : prime)
		{
			if (arr[n - i])
				continue;

			printf("%d = %d + %d\n", n, i, n - i);
			break;
		}
	}

}
