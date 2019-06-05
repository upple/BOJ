#include <iostream>
int main()
{
	int a, b;
	while (1)
	{
		std::cin >> a >> b;
		if (a == 0) return 0;
		if (a - b < b) b = a - b;
		long long ans = 1, r = 1;
		while (r<=b) ans = ans * (a--) / (r++);

		std::cout << ans << "\n";
	}
}