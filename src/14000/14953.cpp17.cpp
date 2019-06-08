#include <bits/stdc++.h>
using namespace std;

inline char read() {
	static int idx = 1 << 17;
	static char buf[1<<18];
	if (idx == 1 << 17) {
		fread(buf, 1, 1 << 17, stdin);
		idx = 0;
	}
	return buf[idx++];
}
inline int readInt() {
	int sum = 0;
	bool flg = 1;
	char now = read();

	while (now == 10 || now == 32) now = read();
	while (now >= 48 && now <= 57) {
		sum = sum * 10 + now - 48;
		now = read();
	}

	return sum;
}

int n, m;
vector<int> adj[100001];
int dp[100001];

int solve(int x)
{
	if(dp[x]) return dp[x];
	
	for(int next : adj[x])
	{
		if(adj[x].size()>=adj[next].size()) continue;
		dp[x]=max(dp[x], dp[next]?dp[next]:solve(next));
	}

	return ++dp[x];
}
int main()
{
	n=readInt(), m=readInt();
	while(m--)
	{
		int a=readInt(), b=readInt();
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int ans=0;
	for(int i=0; i<n; i++)
	{
		ans=max(ans, dp[i]?dp[i]:solve(i));
	}

	printf("%d", ans);
}