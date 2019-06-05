#include<cstdio>
#include<vector>
using namespace std;
int main()
{
	int n, r;
	vector<int> arr(101, -1);
	bool isDie;
	scanf("%d", &n);

	for (int i = 0; i<n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a] = b;
	}
	scanf("%d", &r);
	while (r--)
	{
		int l;
		vector<int> k;
		isDie = false;
		scanf("%d", &l);
		while (l--)
		{
			int d;
			scanf("%d", &d);
			if (arr[d]==-1)
				isDie = true;

			k.push_back(d);
		}

		if (isDie)
			printf("%s\n", "YOU DIED");

		else
		{
			for (auto i : k)
				printf("%d ", arr[i]);

			printf("\n");
		}

	}
}
