#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> T;
int main()
{
	T.push_back(1);
	while (1)
	{
		int num = T.back() + T.size() + 1;
		if (num > 1000)
			break;

		T.push_back(num);
	}
	int t, tsize;
	scanf("%d", &t);
	tsize = T.size();
	while (t--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < tsize; i++)
		{
			int tmp = T[i];
			if (tmp > n) break;
			for (int j = i; j < tsize; j++)
			{
				tmp += T[j];
				if (tmp > n) break;
				if (binary_search(T.begin() + j, T.end(), n - tmp))
				{
					puts("1");
					goto out;
				}
				tmp -= T[j];
			}
		}

		puts("0");
	out:;

	}
}