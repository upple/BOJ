#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#include <cctype>
using namespace std;

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		deque<int> dq;
		int n;
		string cmd;
		cin >> cmd >> n;
		cin.get();
		cin.get();
		if (n == 0)
			cin.get();
		for (int i = 0; i < n; i++)
		{
			int num;
			cin >> num;
			dq.push_back(num);
			cin.get();
		}
		bool chk = 0;
		for (char c : cmd)
		{
			if (c == 'D')
			{
				if (dq.empty())
				{
					puts("error");
					goto out;
				}
				
				if (chk)
					dq.pop_back();

				else
					dq.pop_front();
				
			}
			else
			{
				chk = !chk;
			}
		}

		if (chk)
		{
			reverse(dq.begin(), dq.end());
		}

		cout << "[";
		for (int i = 0; i < dq.size(); i++)
		{
			cout << dq[i];
			if (i != dq.size() - 1)
				cout << ",";
		}

		cout << "]\n";
	out:;
	}
}