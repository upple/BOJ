#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
	unsigned long long num, ans;
	cin >> num;
	ans = (unsigned long long)sqrt(num);
	if (num != ans*ans)
		ans += 1;

	cout << ans << endl;
}