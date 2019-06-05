#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int t, num, arr[10];
	scanf("%d", &t);

	while (t--)
	{
		for (int i = 0; i < 10; i++)
			scanf("%d", &arr[i]);

		sort(arr, arr + 10);
		printf("%d\n", arr[7]);
	}
}