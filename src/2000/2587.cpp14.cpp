#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int num[5], avg=0;
	for(int i=0; i<5; i++)
	{
		scanf("%d", &num[i]);
		avg+=num[i];
	}
	sort(num, num+5);
	printf("%d\n%d\n", avg/5, num[2]);
}
