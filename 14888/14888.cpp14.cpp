#include <cstdio>
#include <algorithm>
using namespace std;

struct Mm
{
	int Max, Min;
};
int n, arr[11], sig[4];

Mm getMaxMin(int num)
{
	static int count = 0;
	int Max = -1111111111, Min=1111111111;

	if (count==n-1)
	{
		return { num, num };
	}

	for (int i = 0; i < 4; i++)
	{
		if (sig[i])
		{
			count++, sig[i]--;
			Mm temp;
			switch (i)
			{
			case 0:
				temp = getMaxMin(num + arr[count]);
				break;
			case 1:
				temp = getMaxMin(num - arr[count]);
				break;
			case 2:
				temp = getMaxMin(num * arr[count]);
				break;
			case 3:
				temp = getMaxMin(num / arr[count]);
				break;
			}

			Max = max(Max, temp.Max);
			Min = min(Min, temp.Min);
			sig[i]++, count--;
		}
	}

	return { Max, Min };
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < 4; i++)
		scanf("%d", &sig[i]);

	auto ans=getMaxMin(arr[0]);
	printf("%d\n%d", ans.Max, ans.Min);
}