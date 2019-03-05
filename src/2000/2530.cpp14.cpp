#include <cstdio>
using namespace std;

int main()
{
	int h, m, s, x;
	scanf("%d %d %d %d", &h, &m, &s, &x);
	s+=m*60+h*60*60+x;
	h=(s/3600)%24, s%=3600;
	m=s/60, s%=60;
	printf("%d %d %d", h, m, s);
	return 0;
}
