#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int black = 0, white = 0;
		string a, b;
		cin >> a >> b;
		for (int i = 0; i < n; i++)
		{
			if (a[i] != b[i])
			{
				if (b[i] == 'W')
					white++;

				else
					black++;
			}
		}

		if (black - white > 0)
			printf("%d\n", black);

		else
			printf("%d\n", white);
	}
}
