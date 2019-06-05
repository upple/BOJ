#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
	map<char, int> m;

	int n[3];
	scanf("%d %d %d", &n[0], &n[1], &n[2]);
	sort(n, n + 3);
	m['A'] = n[0], m['B'] = n[1], m['C'] = n[2];

	char a[4];
	scanf("%s", a);
	for (int i = 0; i < 3; i++)
		printf("%d ", m[a[i]]);
}