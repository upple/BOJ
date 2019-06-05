#include<cstdio>
#include<vector>
using namespace std;

int cunt[2] = {}, t=0;
void dfs(vector<int> &M, vector<vector<int> > &adj, int c, int pos)
{
	M[pos] = c;
	if (adj[pos].size() == 1)
		cunt[c]++;
	else
		t++;
	for (auto i : adj[pos])
		if (M[i] == -1)
			dfs(M, adj, (c + 1) % 2, i);

}
int main()
{
	int v;
	scanf("%d", &v);
	if (v == 1)
	{
		printf("1");
		return 0;
	}
	vector<vector<int> > adj(v + 1);
	vector<int> M(v + 1, -1);
	for (int i = 1; i<v; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(M, adj, 0, 1);
	if (t == 1)
		cunt[0]--, cunt[1]--;
	printf("%d", cunt[0]>cunt[1] ? cunt[0] : cunt[1]);
}
