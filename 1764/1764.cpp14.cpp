#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	int no1, no2, count=0;
	vector<string> str, ans;
	cin >> no1 >> no2;

	str.resize(no1);
	for (int i = 0; i < no1; i++)
		cin >> str[i];

	sort(str.begin(), str.end());
	string temp;
	for (int i = 0; i < no2; i++)
	{
		cin >> temp;
		if (binary_search(str.begin(), str.end(), temp))
		{
			count++;
			ans.push_back(temp);
		}

	}

	sort(ans.begin(), ans.end());
	cout << count << "\n";
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << "\n";

	return 0;
}