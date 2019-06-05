#include<cstdio>

int main()
{
	int A[10];
	int B, a = 0, b = 0;
	char ans, last = 'D';

	for (int i = 0; i < 10; i++)
		scanf("%d", A+i);

	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &B);
		if (A[i] > B)
			a += 3, last = 'A';

		else if (A[i] < B)
			b += 3, last = 'B';

		else
			a++, b++;
	}

	if (a > b)
		ans = 'A';

	else if (b > a)
		ans = 'B';

	else
		ans = last;

	printf("%d %d\n%c\n", a, b, ans);
}