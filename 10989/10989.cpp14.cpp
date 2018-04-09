#include<cstdio>
#include<map>
using namespace std;

int main()
{
	map<int, long long> M;
	long long n;
	int num;
	scanf("%lld", &n);
	for(long long i=0; i<n; i++)
	{
		scanf("%d", &num);
		M[num]++;
	}
	for(int i=1; i<=10000; i++)
	{
		long long s=M[i];
		for(long long j=0; j<s; j++)
			printf("%d\n", i);
	}
}
