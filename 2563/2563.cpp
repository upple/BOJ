#include <cstdio>

bool arr[101][101];
int cnt;
int main()
{
	int n;
	scanf("%d", &n);

	while(n--)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		for(int i=a+9; i>=a; i--)
		{
			for(int j=b+9; j>=b; j--)
			{
				if(!arr[i][j])
				{
					cnt++;
					arr[i][j]=1;
				}
			}
		}
	}

	printf("%d", cnt);
}
