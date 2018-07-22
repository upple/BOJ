#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	vector<int> line;
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
	{
		int k;
		scanf("%d", &k);
		line.insert(line.begin()+k, i);
	}

	for(int i=0; i<n; i++)
		printf("%d ", line[n-1-i]);
}
