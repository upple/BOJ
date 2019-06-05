#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
struct xy { double x, y; };
const double INF = 999999999.0;
xy arr[102];
double d[102];
bool inQ[102];
inline double getDist(xy &a, xy &b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
int main()
{
	double x, y;
	for (int i = 0; i < 2; i++)
	{
		cin >> x >> y;
		arr[i] = { x, y };
	}
	int n;
	cin >> n;
	for (int i = 2; i < n + 2; i++)
	{
		cin >> x >> y;
		arr[i] = { x, y };
	}

	d[0] = 0;
	queue<int> Q;
	for (int i = 1; i < n + 2; i++)
		d[i] = getDist(arr[0], arr[i]) / 5.0, Q.push(i), inQ[i] = 1;

	while (Q.size())
	{
		int cur = Q.front();
		Q.pop();
		inQ[cur] = 0;

		for (int i = 0; i < n + 2; i++)
		{
			if (i == cur) continue;
			double dist = getDist(arr[cur], arr[i]);
			double cost = min(dist / 5.0, 2 + abs(dist - 50.0) / 5.0);
			if (d[i] > d[cur] + cost)
			{
				d[i] = d[cur] + cost;
				if (!inQ[i])
					inQ[i] = 1, Q.push(i);
			}
		}
	}

	cout << d[1];
}