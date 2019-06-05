#include <iostream>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

int n;
vector<int> arr;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		arr.resize(n);
		bool chk = true;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		vector<int> zero(n, 0);
		set<vector<int> > S;
		while (1)
		{
			if (arr == zero)
			{
				cout << "ZERO\n";
				break;
			}

			if (S.find(arr) != S.end())
			{
				cout << "LOOP\n";
				break;
			}
            
			S.insert(arr);
			int s = arr[0];
			for (int i = 0; i < n - 1; i++)
			{
				arr[i] = abs(arr[i] - arr[i + 1]);
			}
            
			arr[n - 1] = abs(arr[n - 1] - s);
		}
	}
}