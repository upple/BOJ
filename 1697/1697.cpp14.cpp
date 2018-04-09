#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int start, end, point, count = 0;
	bool visit[100001] = { 0, };
	queue<int> Queue;
	cin >> start >> end;
	Queue.push(start);
	visit[start] = true;
	Queue.push(-1);
	while (1)
	{
		point = Queue.front();
		Queue.pop();
		if (point == end)
			break;

		if (point == -1)
		{
			count++;
			Queue.push(-1);
			continue;
		}
		
		visit[point] = true;
		if (point>0 && visit[point - 1] == false)
			Queue.push(point - 1);

		if (point<end && visit[point + 1] == false)
			Queue.push(point + 1);

		if (point<end && point * 2 <= 100000 && visit[point * 2] == false)
			Queue.push(point * 2);

	}

	cout << count << endl;

}