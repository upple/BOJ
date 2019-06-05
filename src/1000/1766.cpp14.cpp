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

	priority_queue<int> pq;
	for (int i = 1; i <= n; i++)
		if (!in[i]) pq.push(-i);

	while (pq.size())
	{
		int cur = -pq.top();
		cout << cur << " ";
		pq.pop();
		for (int i : adj[cur])
		{
			if (!--in[i]) pq.push(-i);
		}
	}
}