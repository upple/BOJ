#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	string str;
	stack<char> S;
	stack<int> T;
	int ans = 0, tmp, cur;
	cin >> str;
	T.push(0);
	for(char ch : str)
	{
		switch (ch)
		{
		case '(': case '[':
			S.push(ch), T.push(0); break;

		case ')':
			if (S.empty() || S.top()!='(')
				goto fail;

			S.pop();
			tmp = T.top();
			T.pop();
			cur = T.top();
			T.pop();
			cur += tmp == 0 ? 2 : tmp * 2;
			T.push(cur);
			break;

		case ']':
			if (S.empty() || S.top() != '[')
				goto fail;

			S.pop();
			tmp = T.top();
			T.pop();
			cur = T.top();
			T.pop();
			cur += tmp == 0 ? 3 : tmp * 3;
			T.push(cur);
		}
	}

	if (S.size())
		goto fail;

	printf("%d", T.top());
	return 0;

fail:
	putchar('0');
}