#include <cstdio>

bool arr[3072][6144];
bool sample[3][5] = { 
{0, 0, 1, 0, 0},
{0, 1, 0, 1, 0},
{1, 1, 1, 1, 1} };
char star[] = { ' ', '*' };
void draw(int n, int x, int y)
{
	if (n == 3)
	{
		for (int i = x; i < x + 3; i++)
			for (int j = y; j < y + 5; j++)
				arr[i][j] = sample[i - x][j - y];

		return;
	}
	draw(n / 2, x, y + n / 2);
	draw(n / 2, x + n / 2, y);
	draw(n / 2, x + n / 2, y + n);
}
int main()
{
	int n;
	scanf("%d", &n);

	draw(n, 0, 0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2 * n - 1; j++)
			printf("%c", star[arr[i][j]]);

		printf("\n");
	}
}