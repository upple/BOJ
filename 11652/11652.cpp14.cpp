#include<cstdio>
#include<map>
using namespace std;

int main()
{
	map<long long, int> M;
	int n;
	long long num, ans=0;
	scanf("%d", &n);

	for(int i=0; i<n; i++)
	{
		scanf("%lld", &num);
		int &A=M[ans], &B=++M[num];
		if(A<B)
			ans=num;

		else if(A==B)
			ans=(ans<num?ans:num);
	}

	printf("%lld\n", ans);
}
