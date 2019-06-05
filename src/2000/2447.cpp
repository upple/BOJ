#include <cstdio>

char arr[2187][2187];
char star[2]={' ', '*'};
void printStar(int x, int y, int n)
{
	if(n==0)
	{
		arr[x][y]=1;
		return;
	}
	n/=3;
	printStar(x, y, n);
	printStar(x+n, y, n);
	printStar(x+n+n, y, n);
	printStar(x, y+n, n);
	printStar(x, y+n+n, n);
	printStar(x+n, y+n+n, n);
	printStar(x+n+n, y+n, n);
	printStar(x+n+n, y+n+n, n);

}
int main()
{
	int n;
	scanf("%d", &n);

	printStar(0, 0, n);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			printf("%c", star[arr[i][j]]);

		printf("\n");
	}
}
