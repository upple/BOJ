#include<cstdio>
using namespace std;

int main()
{
	int arr[5], sum=0;
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &arr[i]);
		if (arr[i] < 40)
			arr[i] = 40;

		sum += arr[i];
	}

	printf("%d\n", sum / 5);
	return 0;
}