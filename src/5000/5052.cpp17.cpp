#include <bits/stdc++.h>
using namespace std;
int arr[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin>>t;

	while (t--)
	{
		int n, root = 0, s = 10;
		bool check = 1;
		char num[11];
        memset(arr, 0, sizeof(arr));
		cin>>n;

		for (int i = 0; i < n; i++)
		{
			cin>>num;
			int p = num[0] - '0';
			for (int j = 0; num[j+1] && check; j++)
			{
				switch (arr[p])
				{
				case -1:
					check = 0;
					break;
				case 0:
					arr[p] = s;
					s += 10;
				
				default:
					p = arr[p] + num[j + 1] - '0';
				}
			}
			if (arr[p] != 0)
				check = 0;
			arr[p] = -1;
		}

		cout<<(check ? "YES\n" : "NO\n");
	}
}