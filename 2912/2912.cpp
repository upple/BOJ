#include <iostream>
using namespace std;

int arr[300001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, c, m;
	cin >> n >> c;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	cin >> m;
	
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		int cnt[10001] = {}, size = b - a + 1;
		bool chk = 1;
		for (int i = a; i <= b; i++)
		{
			if (++cnt[arr[i]] > size / 2)
			{
				cout << "yes " << arr[i] << "\n";
				chk = 0;
				break;
			}
			
		}

		if (chk)
		{
			cout << "no\n";
		}
	}

}