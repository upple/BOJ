#include <cstdio>

int main()
{
	int arr[6]={};
	int n;
	scanf("%d", &n);
	if(n==3)
	{
		for(int i=0; i<3; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			arr[a]++, arr[b]++;
		}

		if(arr[1]==2 && arr[3]==2 && arr[4]==2)
		{
			printf("Wa-pa-pa-pa-pa-pa-pow!");
			return 0;
		}
	}
	printf("Woof-meow-tweet-squeek");
}
