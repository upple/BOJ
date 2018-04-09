#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string T, P;
	getline(cin, T);
	getline(cin, P);
	vector<int> Pi(P.size()), ans;

	for (int i = 1, j = 0; i < P.size(); i++)
	{
		while (j > 0 && P[i] != P[j])
			j = Pi[j - 1];

		if (P[i] == P[j])
			Pi[i] = ++j;
	}

	for (int i = 0, j = 0; i < T.size(); i++)
	{
		while (j > 0 && T[i] != P[j])
			j = Pi[j - 1];

		if (T[i] == P[j])
		{
			if (j == P.size() - 1)
			{
				ans.push_back(i - j + 1);
				j = Pi[j];
			}

			else
				j++;
		}
	}

	cout << ans.size() << '\n';

	for (auto i : ans)
		cout << i << '\n';
}