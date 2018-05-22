#include <cstdio>
#include <stack>
#include <vector>
using namespace std;
int main()
{
	int n, num;
	stack<int> S;
	vector<char> ans;
	scanf("%d", &n);

	for(int i=1, j=1; i<=n; i++)
	{
		scanf("%d", &num);
		do
		{
			if (num < j)
			{
				if (S.empty() || S.top() != num)
				{
					puts("NO");
					return 0;
				}

				ans.push_back('-');
				S.pop();
				break;
			}

			else
			{
				S.push(j);
				ans.push_back('+');
			}
		} while (++j);

	}

	for (char ch : ans)
		printf("%c\n", ch);
}