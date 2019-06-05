#include <iostream>
#define N 58
using namespace std;

bool adj[N][N];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, cnt = 0;
	char a, b;
	char str[3];
	cin >> n;

	while (n--)
	{
		cin >> a >> str >> b;

		if (!adj[a - 'A'][b - 'A'] && a != b)
			cnt++, adj[a - 'A'][b - 'A'] = 1;
	}

	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (i != j && !adj[i][j] && adj[i][k] && adj[k][j])
					cnt++, adj[i][j] = 1;

	cout << cnt << "\n";
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (adj[i][j])
				cout << (char)(i + 'A') << " => " << (char)(j + 'A') << "\n";
}