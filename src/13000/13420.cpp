#include <cstdio>

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		long long a, b, c, ans;
		char r, e;
		scanf("%lld %c %lld %c %lld", &a, &r, &b, &e, &c);

		switch (r)
		{
		case '+':
			ans = a + b;	break;
		case '-':
			ans = a - b;	break;
		case'*':
			ans = a*b;	break;
		case'/':
			ans = a / b;	break;
		}

		printf("%s\n", (ans == c ? "correct" : "wrong answer"));
	}
}