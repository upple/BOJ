#include <cstdio>
#include <stack>
using namespace std;
int main()
{
	int n, cnt=0;
	scanf("%d", &n);
	while(n--)
	{
		stack<int> S;
		char str[100001];
		scanf("%s", str);
		for(int i=0; str[i]; i++)
		{
			if(S.empty() || S.top()!=str[i])
				S.push(str[i]);

			else
				S.pop();
		}

		if(S.empty())
			cnt++;
	}

	printf("%d", cnt);
}
