#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string b;
	int m;
	int arr[1001] = {};
	cin >> m;

	while (cin >> b)
	{
		if (b.size() >= 3)
			b = b.substr(2, b.size()-2);

		int it = m*stoi(b)/(int)pow(10, b.size());
		arr[it]++;
	}

	for (int i = 0; i < m; i++)
		cout << arr[i] << " ";
}