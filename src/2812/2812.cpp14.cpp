#include <iostream>
#include <stack>
using namespace std;
stack<char> num;
int main()
{
	int n, k;
	char tmp;
	cin >> n >> k;
	cin.get();
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;

		while (k && num.size() && num.top() < tmp)
		{
			num.pop();
			k--;
		}
		num.push(tmp);

	}
	while (k--)
	{
		num.pop();
	}
	int it = 0;
	char ans[500001];
	while (num.size())
	{
		ans[it++] = num.top();
		num.pop();
	}

	for (int i = it-1; i>=0; i--)
	{
		cout << ans[i];
	}
}