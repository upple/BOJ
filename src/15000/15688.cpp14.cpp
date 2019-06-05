#include <iostream>
#include <map>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, num;
	map<int, int> M;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		M[num]++;
	}
	
	for (auto &i : M)
	{
		while (i.second--)
			cout << i.first << "\n";
	}

}