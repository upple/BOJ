#include <cstdio>
#include <string>

using namespace std;

int main()
{
	int a, b, c, d, num, ans=0;
	for(int i=0; i<5; i++)
	{
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if(ans<a+b+c+d)
			num=i+1, ans=a+b+c+d;
	}

	printf("%d %d\n", num, ans);
	return 0;
}
