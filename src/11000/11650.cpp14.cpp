#include<cstdio>
#include<algorithm>

using namespace std;

class XY
{
public:
	int x, y;
};

int compare(XY &a, XY &b)
{
	if(a.x==b.x)
		return b.y-a.y>0;

	return b.x-a.x>0;
}
int main()
{
	int no_case;
	int x, y;
	scanf("%d", &no_case);
	XY *arr=new XY[no_case];

	for(int i=0; i<no_case; i++)
		scanf("%d %d", &(arr[i].x), &(arr[i].y));

	sort(arr, arr+no_case, compare);
	for(int i=0; i<no_case; i++)
		printf("%d %d\n", arr[i].x, arr[i].y);

	delete []arr;
	return 0;
}
