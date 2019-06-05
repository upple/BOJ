#include <cstdio>
#include <string>
using namespace std;

int main()
{
	 long long num;
	 int count = 0;
	 scanf("%lld", &num);

	 while (num >= 10)
	 {
		 count++;
		 string str = to_string(num);
		 num = 1;
		 for (auto i : str)
			 num *= (i - '0');
	 }

	 printf("%d", count);
}