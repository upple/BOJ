#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
int main()
{
	int n, k;
	vector<int> d1, d2;
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= (sqrt(n)); i++)
	{
		if (i*i == n)
			d1.push_back(i);
		else if (!(n%i))
			d1.push_back(i), d2.push_back(n / i);
	}

	if(k>d1.size()+d2.size())
		printf("0\n");

	else if (k <= d1.size())
		printf("%d\n", d1[k - 1]);

	else
		printf("%d\n", d2[d2.size() + d1.size() - k]);
}
