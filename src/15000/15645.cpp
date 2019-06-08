#include <iostream>
#include <algorithm>
using namespace std;

int maxDp[5][2], minDp[5][2], input[3];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	cin >> maxDp[1][0] >> maxDp[2][0] >> maxDp[3][0];
	minDp[1][0] = maxDp[1][0], minDp[2][0] = maxDp[2][0], minDp[3][0] = maxDp[3][0];
	minDp[0][0] = minDp[4][0] = 999999999;
	while(--n)
	{
		cin >> input[0] >> input[1] >> input[2];
		for (int j = 1; j <= 3; j++)
		{
			maxDp[j][1] = input[j - 1] + max(maxDp[j][0], max(maxDp[j - 1][0], maxDp[j + 1][0]));
			minDp[j][1] = input[j - 1] + min(minDp[j][0], min(minDp[j - 1][0], minDp[j + 1][0]));
		}

		for (int j = 1; j <= 3; j++)
		{
			maxDp[j][0] = maxDp[j][1];
			minDp[j][0] = minDp[j][1];
		}

	}

	cout << max(max(maxDp[1][0], maxDp[2][0]), maxDp[3][0]) << " " << min(min(minDp[1][0], minDp[2][0]), minDp[3][0]);
}