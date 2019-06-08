#include <cstdio>
#include <cmath>

int tree[2100000], k, no_data;
int update(int x)
{
	int a, b;
	if(x*2>no_data)
		return tree[x];

	a=update(x*2), b=update(x*2+1);
	if(a>b)
	{
		tree[x*2+1]+=a-b;
		return a+tree[x];
	}
	else
	{
		tree[x*2]+=b-a;
		return b+tree[x];
	}
}

long long solve(int x)
{
	if(x*2>no_data)
		return tree[x];

	return solve(x*2)+solve(x*2+1)+tree[x];
}
int main()
{
	scanf("%d", &k);
	no_data=pow(2, k+1)-1;
	for(int i=2; i<=no_data; i++)
	{
		scanf("%d", &tree[i]);
	}

	update(1);
	printf("%lld", solve(1));
}
