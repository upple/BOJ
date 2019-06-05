#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

class xy
{
public:
	int x, y;
	xy(int a, int b): x(a), y(b){};
	bool operator <(const xy& a) const
	{
		if(y!=a.y)
			return y<a.y;

		return x<a.x;
	}
};
int main()
{
	vector<xy>points;
	int no_xy;
	scanf("%d", &no_xy);
	for(int i=0; i<no_xy; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		points.push_back(xy(x, y));
	}

	sort(points.begin(), points.end());

	for(int i=0; i<no_xy; i++)
		printf("%d %d\n", points.at(i).x, points.at(i).y);

	return 0;
}
