#include <cstdio>
#include <map>
#include <cmath>
using namespace std;

int main()
{
	map<int, bool> M;
	int a, p;
	scanf("%d %d", &a, &p);
	bool check = false;
	while (1)
	{
		bool &r = M[a];
		if (r)
			check = true, M.erase(a);

		else if (check)
			break;

		else
			r = true;

		int temp = a;
		a = 0;
		while (temp)
		{
			int t;
			t = (int)pow(temp % 10, p);
			a += t, temp /= 10;
		}
	}
	printf("%d ", M.size()-1);
}