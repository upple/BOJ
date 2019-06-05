#include <iostream>
#include <string>
using namespace std;

int arr[2][21][101];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string str, s[2];
	cin >> str >> s[0] >> s[1];
	
	for (int i = 1; i <= s[0].size(); i++)
	{
		for (int j = 1; j <= str.size(); j++)
		{
			for (int k = 0; k < 2; k++)
			{
				arr[k][j][i] = arr[k][j][i - 1];

				if (str[j - 1] == s[k][i - 1])
				{
					if (j == 1)
						arr[k][j][i] += 1;

					else
						arr[k][j][i] += arr[1 - k][j - 1][i - 1];

				}


			}
		}
	}


	cout<<arr[0][str.size()][s[0].size()] + arr[1][str.size()][s[0].size()];
}