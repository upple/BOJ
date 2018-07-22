#include <iostream>

using namespace std;

int count = 0;

int dfs(int n)
{
	if (n < 0)
		return 0;
	else if (n == 1 || n==0)
		return 1;

	else
		return dfs(n - 1) + dfs(n - 2) + dfs(n - 3);
}

int main(void)
{
	int no_case, number;
	cin >> no_case;
	while (no_case--)
	{
		cin >> number;
		cout << dfs(number) << endl;
	}
	
	return 0;
}