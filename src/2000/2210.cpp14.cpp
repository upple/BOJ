#include <cstdio>
#include <string>
#include <set>
using namespace std;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
char map[5][5];

set<string> ans;
string str;
void solve(int x, int y, int c)
{
	str.push_back(map[x][y]);
	if (c == 5)
	{
		ans.insert(str);
		str.pop_back();
		return;
	}

	for (int i = 4; i--;)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5)
		{
			solve(nx, ny, c + 1);
		}
	}

	str.pop_back();
}
int main()
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			scanf("%c ", &map[i][j]);

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			solve(i, j, 0);

	printf("%d", ans.size());
}