#include <iostream>
#include <unordered_set>
using namespace std;
const unsigned int SET = 0xfffff;
unsigned int arr[100001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    
	int n, m;
	unordered_set<unsigned int> S;
	cin >> n >> m;

	while (m--)
	{
		int a, b, c;
		cin >> a >> b;
		if (a == 1 || a == 2)
			cin >> c;

		switch (a)
		{
		case 1:
			arr[b] = SET & (arr[b] | (1 << (c - 1))); break;
		case 2:
			arr[b] = SET & (arr[b] & ~(1 << (c - 1))); break;
		case 3:
			arr[b] = SET & (arr[b] << 1); break;
		case 4:
			arr[b] = arr[b] >> 1;
		}
	}

	for (int i = 1; i <= n; i++)
		if (S.find(arr[i]) == S.end())
			S.insert(arr[i]);

	cout << S.size();
}