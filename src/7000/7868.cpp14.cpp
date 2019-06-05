#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	long long k_num;
	int n[3] = { 0, };
	vector<long long> hamming;
	vector<long long> temp;

	cin >> n[0] >> n[1] >> n[2] >> k_num;
	sort(n, n+3);
	hamming.push_back(n[0]);

	for (int j = 0; j<k_num - 1; j++)
	{
		if (hamming[j] % n[2] == 0)
			temp.push_back(hamming[j] * n[2]);

		else if (hamming[j] % n[1] == 0)
		{
			temp.push_back(hamming[j] * n[1]);
			temp.push_back((hamming[j] / n[1])*n[2]);
		}

		else
		{
			temp.push_back(hamming[j] * n[0]);
			temp.push_back((hamming[j] / n[0])*n[1]);
		}

		for (int k = 0; k < temp.size() - 1; k++)
		{
			if (temp[k] < temp[k + 1])
				swap(temp[k], temp[k + 1]);
		}

		hamming.push_back(temp[temp.size() - 1]);
		temp.pop_back();
	}

	cout << hamming.back() << endl;
	return 0;
}
