#include<cstdio>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;

void check(int num)
{
	string k = to_string(num);
	reverse(k.begin(), k.end());
	if (to_string(num) == k)
		printf("%d\n", num);
}
int main()
{
	int s, e;
	scanf("%d %d", &s, &e);
	vector<bool> arr((int)sqrt(e)+2);
	vector<int> dp;
	set<int> pel;
	for (int i = 2; i < arr.size(); i++)
	{
		if (!arr[i])
		{
			dp.push_back(i);
			int temp = i+i;
			while (temp < arr.size())
				arr[temp] = true, temp += i;

		}
	}
	for (int i = 1; i <= 9999; i++)
	{
		string temp = to_string(i);
		string temp2 = temp;
		reverse(temp.begin(), temp.end());
		pel.insert(stoi(temp2 + temp));
		temp2.pop_back();
		pel.insert(stoi(temp2 + temp));
	}

	for (auto i : pel)
	{
		if (i < s)
			continue;

		if (i > e)
			break;

		bool prime = true;
		for (auto j : dp)
		{
			if (!(i%j))
			{
				prime = false;
				break;
			}
			if (j >= sqrt(i))
				break;
		}

		if (prime)
			printf("%d\n", i);

	}
	printf("-1\n");
}