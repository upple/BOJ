#include <cstdio>

int main()
{
	int arr[501][501]={}, n, ans=0;
	scanf("%d", &n);

	while(n--)
	{
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		for(int i=x1; i<x2; i++)
			for(int j=y1; j<y2; j++)
				if(!arr[i][j])
					ans++, arr[i][j]=1;

	}

	printf("%d", ans);

}
