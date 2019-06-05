#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
	int ans = 222222222;
	int n, num;
	multiset<int> S;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		S.insert(num);
	}

	if (*S.begin() >= 0)
	{
		printf("%d", *S.begin() + *(++S.begin()));
		return 0;
	}

	else if (*(--S.end()) <= 0)
	{
		printf("%d", *--S.end() + *--(--S.end()));
		return 0;
	}

	S.insert(999999999);
	int cur = *S.begin();
	while (cur < 0)
	{
		
		S.erase(S.begin());
		auto it = S.lower_bound(-cur);
		auto nit = it;
		
		if (it != S.begin())
			nit--;
			
		if (abs(cur + *it) > abs(cur + *nit))
			cur = cur + *nit;
		
		else
			cur = cur + *it;

		if (abs(ans) > abs(cur))
			ans = cur;

		cur = *S.begin();
	}

	printf("%d", ans);
}