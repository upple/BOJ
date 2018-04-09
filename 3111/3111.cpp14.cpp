#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string F, B, a, t, ra, ans;
	cin >> a >> t;
	ra = a;
	reverse(ra.begin(), ra.end());

	int aSize = a.size(), tSize = t.size();
	int fIt = 0, bIt = tSize - 1;

	while (fIt<=bIt)
	{
		for (int &i = fIt; i <= bIt; i++)
		{
			F.push_back(t[i]);
			if (F.size()>=aSize && F.substr(F.size() - aSize, aSize) == a)
			{
				F.erase(F.end() - aSize, F.end());
				i++;
				break;
			}
		}

		for (int &i = bIt; i >= fIt; i--)
		{
			B.push_back(t[i]);
			if (B.size() >= aSize && B.substr(B.size() - aSize, aSize) == ra)
			{
				B.erase(B.end() - aSize, B.end());
				i--;
				break;
			}
		}
	}

	reverse(B.begin(), B.end());
	ans = F + B;
	auto it = ans.find(a);
	while (it != string::npos)
	{
		ans.erase(it, aSize);
		it = ans.find(a);
	}

	cout << ans;
}