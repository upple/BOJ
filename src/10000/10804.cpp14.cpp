#include <cstdio>
#include <algorithm>
using namespace std;


int main()
{
	int arr[20];
	for(int i=1; i<=20; i++)
		arr[i]=i;

	for(int i=0; i<10; i++)
	{
		int s, e;
		scanf("%d %d", &s, &e);
		reverse(arr+s, arr+e+1);
	}
	for(int i=1; i<=20; i++)
		printf("%d ", arr[i]);

	return 0;
}
