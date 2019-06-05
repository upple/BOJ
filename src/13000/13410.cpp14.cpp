#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int n, k, max=0;
	scanf("%d %d", &n, &k);

	for(int i=1; i<=k; i++)
	{
		int temp;
		string to_s=to_string(n*i);
		reverse(to_s.begin(), to_s.end());
		temp=stoi(to_s);
		if(max<temp)
			max=temp;
	}

	printf("%d", max);
}
