#include<cstdio>
#include<vector>
#include<unordered_map>
using namespace std;

unordered_map<int, bool> q;

int main()
{

	int k, n;
	scanf("%d %d", &k, &n);
	vector<int> arr(n), ans;
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for (int i = n - 1; i >= 0; i--)
	{
		if (q[arr[i]])
		{
			arr[i] = -1;
			continue;
		}

		q[arr[i]] = true;
	}

	for (int i = 0, j = 0; j < k && i<arr.size(); i++)
	{
		if (arr[i] == -1)
			continue;

		printf("%08d\n", arr[i]);
		j++;
	}

	return 0;
}
