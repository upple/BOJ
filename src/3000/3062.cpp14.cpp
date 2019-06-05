#include<iostream>
#include<string>

using namespace std;

int main()
{
	int no_case;

	cin >> no_case;
	for (int i = 0; i<no_case; i++)
	{
		string num, reverse, sum, sum_reverse;
		int n1, n2;
		cin >> num;
		for (int j = 0; j < num.size(); j++)
			reverse += num[num.size() - j - 1];

		n1 = stoi(num), n2 = stoi(reverse);
		sum = to_string(n1 + n2);
		for (int j = 0; j<sum.size(); j++)
			sum_reverse +=sum[sum.size() - j - 1];

		if (sum.compare(sum_reverse))
			cout << "NO" << endl;

		else
			cout << "YES" << endl;
	}

	return 0;
}
