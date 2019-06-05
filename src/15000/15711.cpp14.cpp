#include <iostream>
#include <vector>
using namespace std;
bool arr[2000001];
vector<int> V;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	for (int i = 2; i <= 2000000; i++)
	{
		if (!arr[i])
		{
			int tmp = i;
			V.push_back(i);
			while (tmp <= 2000000)
			{
				arr[tmp] = 1;
				tmp += i;
			}
		}
	}
	while (t--)
	{
		long long a, b;
		cin >> a >> b; 
		a = a + b;
		if (a > 4 && !(a % 2))
		{
			cout << "YES\n";
			continue;
		}
		bool check = 0;
		for (int i : V)
		{
			long long cond = a - i;
			if (cond < 2)
				break;

			check = 1;
			for (int j : V)
			{
				if (j*j > cond)
					break;

				if (!(cond%j))
				{
					check = 0;
					break;
				}
			}

			if (check)
			{
				cout << "YES\n";
				break;
			}
		}

		if(!check)
			cout << "NO\n";
	}
}