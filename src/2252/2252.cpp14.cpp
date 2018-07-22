#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[32001];
int in[32001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		in[b]++;
	}
	queue<int> Q;
	for (int i = 1; i <= n; i++)
		if (in[i] == 0) Q.push(i);

	while (Q.size())
	{
		int cur = Q.front();
		cout << cur << " ";
		Q.pop();
		for (int i : adj[cur])
		{
			if (!--in[i])
				Q.push(i);
		}
	}
}