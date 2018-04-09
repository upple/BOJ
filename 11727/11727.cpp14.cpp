#include <iostream>
#include <vector>

using namespace std;

vector<int> cash;
int fibo(int n)
{
	if (cash.size() >= n)
		return cash[n - 1];

	for (int i = 2; i<n; i++) {
		cash.push_back((cash[i - 1] + cash[i - 2]*2) % 10007);
	}
	return cash[n - 1];
}

int main()
{
	int num;
	cash.push_back(1);
	cash.push_back(3);
	cin >> num;
	cout << fibo(num) << endl;

	return 0;
}