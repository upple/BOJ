#include<iostream>

using namespace std;

int cash[11] = { 1, 1, };
int last_pos = 1;
int fact(int n)
{
	if (cash[n] != 0)
		return cash[n];

	for (int i = last_pos; i < n; i++)
		cash[i+1] = cash[i]*(i+1);

	last_pos = n;
	return cash[n];
}
int main()
{
	int n, k, ans;
	cin >> n >> k;

	ans = fact(n) / (fact(k)*fact(n - k));
	cout << ans << endl;

	return 0;
}