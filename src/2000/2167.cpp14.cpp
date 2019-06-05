#include<cstdio>
using namespace std;

int main()
{
	int row, col, no_case, a, b, x, y, pos, ans;
	int arr[301][301];
	scanf("%d %d", &row, &col);
	for(int i=1; i<=row; i++)
		for(int j=1; j<=col; j++)
		{
			scanf("%d", &pos);
			arr[i][j]=pos;
		}

	scanf("%d", &no_case);
	while(no_case--)
	{
		ans=0;
		scanf("%d %d %d %d", &a, &b, &x, &y);

		for(int i=a; i<=x; i++)
			for(int j=b; j<=y; j++)
				ans+=arr[i][j];

		printf("%d\n", ans);
	}
	return 0;
}
