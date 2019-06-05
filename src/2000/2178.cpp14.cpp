#include <iostream>
#include <queue>
using namespace std;

const int MAX_SIZE = 101;
const int DIRECTION[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

bool isPossible(int row, int col, int x, int y, bool visit[][MAX_SIZE])
{
	return (x >= 0 && x < row && y >= 0 && y < col && !visit[x][y]);
}
int main()
{
	char board[MAX_SIZE][MAX_SIZE];
	bool visit[MAX_SIZE][MAX_SIZE] = { 0, };
	int row, col, count = 1, x, y;
	queue<int> Queue[2];
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		cin >> board[i];

	Queue[0].push(0), Queue[1].push(0);
	Queue[0].push(-1), Queue[1].push(-1);
	visit[0][0] = true;
	while (1)
	{
		x = Queue[0].front(), y=Queue[1].front();
		Queue[0].pop(), Queue[1].pop();
		if (x == row - 1 && y == col - 1)
			break;

		if (x == -1)
		{
			count++;
			Queue[0].push(-1), Queue[1].push(-1);
			continue;
		}

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + DIRECTION[i][0], next_y = y + DIRECTION[i][1];
			if (isPossible(row, col, next_x, next_y, visit) && board[next_x][next_y]=='1')
				Queue[0].push(next_x), Queue[1].push(next_y), visit[next_x][next_y] = true;
		}

	}

	cout << count << endl;
}