#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;


vector<int> ff;
int fibo(int n)
{
	if (ff.size() > n + 1)
		return ff.at(n);

	for (int i = ff.size() - 1; i < n + 1; i++)
	{
		int temp = ff[i] + ff[i - 1];
		ff.push_back(temp);
	}

	return ff.at(n);
}

int main()
{
	ff.push_back(0);
	ff.push_back(1);
	int n;
	scanf("%d", &n);
	printf("%d\n", fibo(n));
}
