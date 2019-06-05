#include <cstdio>
#define max(x, y) (x>y?x:y)
#define min(x, y) (x<y?x:y)
using namespace std;

int main()
{
	int a=0, b=0, c=0, d=0, e=0, f=0;
	int n;
	scanf("%d", &n);
	while(n--)
	{
		int ta, tb, tc;
		int arr[2][3];
		scanf("%d %d %d", &ta, &tb, &tc);
		arr[0][0]=max(a, b)+ta;
		arr[0][1]=max(max(a, b), c)+tb;
		arr[0][2]=max(b, c)+tc;
		arr[1][0]=min(d, e)+ta;
		arr[1][1]=min(min(d, e), f)+tb;
		arr[1][2]=min(e, f)+tc;

		a=arr[0][0], b=arr[0][1], c=arr[0][2];
		d=arr[1][0], e=arr[1][1], f=arr[1][2];
	}

	printf("%d %d\n", max(max(a, b), c), min(min(d, e), f));
	return 0;
}
