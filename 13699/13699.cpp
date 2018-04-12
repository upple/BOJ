#include <iostream>
using namespace std;

long long arr[36] = { 1, };
int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			arr[i] += arr[j] * arr[i - j - 1];
		}
	}

	cout << arr[n];
}