#include <iostream>
#include <sstream>
#include <string>
using namespace std;

ostringstream ss;
int solve(int x, int f, int t)
{
	int res = 0;
	int m = 6 - f - t;
	if (x == 1)
	{
		ss << f << " " << t << "\n";
		return 1;
	}

	res += solve(x - 1, f, m) + 1;
	ss << f << " " << t << "\n";
	return res += solve(x - 1, m, t);
}
int main()
{
	ios_base::sync_with_stdio(0);
	ss.tie(0);
	cin.tie(0);
	int n;
	ss << "\n";
	cin >> n;
	cout << solve(n, 1, 3);
	cout << ss.str();

}