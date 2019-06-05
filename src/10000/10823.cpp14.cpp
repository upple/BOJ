#include<cstdio>
#include<string>
#include<cctype>

using namespace std;

int main()
{
	char num;
	long long ans = 0;
	string temp="0";

	while (scanf("%c", &num) != EOF)
	{
		if (num==',')
			ans += stol(temp), temp = "0";

		else if(isdigit(num))
			temp += num;

	}

	ans += stoi(temp);
	printf("%lld\n", ans);
	return 0;
}