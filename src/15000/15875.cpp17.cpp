
#include <bits/stdc++.h>
using namespace std;

char buf[1 << 17];
inline char read() {
	static int idx = 1 << 17;
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
	if (now == '-') flg = 0, now = read();
	while (now >= 48 && now <= 57) {
		sum = sum * 10 + now - 48;
		now = read();
	}

	return flg ? sum : -sum;
}

int w, h;
vector<pair<int, int> > M;
int arr[1000][1000], p[1000][1000], s[1000][1000];
const int dx[] = { 0, 0, 1, -1 };
const int dy[] = { 1, -1, 0, 0 };

int Find(int a)
{
	int x = a >> 10, y = a & 0x3ff;
	if (p[x][y] == a) return a;
	return p[x][y] = Find(p[x][y]);
}
void Union(int ax, int ay, int bx, int by)
{
	int a = Find((ax << 10) + ay);
	int b = Find((bx << 10) + by);
	ax = a >> 10, ay = a & 0x3ff;
	bx = b >> 10, by = b & 0x3ff;
	p[bx][by] = p[ax][ay];

	if (s[ax][ay] == 0 || s[bx][by] == 0) s[ax][ay] = 0;
	else s[ax][ay] += s[bx][by];
}
int main()
{
	h=readInt();
	w=readInt();

	M.resize(w*h);
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			arr[i][j]=readInt();
			M[i*w + j] = { arr[i][j], (i << 10) + j };
			p[i][j] = (i << 10) + j;
			s[i][j] = (i >= 1 && i < h - 1 && j >= 1 && j < w - 1);
		}
	}

	sort(M.begin(), M.end());
	int ans = 0, size = 0, lastl = -1, lasti=0;
	for(int u=0; u<M.size(); u++)
	{
		int l = M[u].first;
		int cur = M[u].second;
		if (l != lastl) 
		{
			for(int i=lasti; i<u; i++)
			{
				int a=Find(M[i].second);
				ans=max(ans, s[a>>10][a&0x3ff]);
			}

			lastl=l, lasti=u;
		}
		int x = cur >> 10, y = cur & 0x3ff;
		
		for (int i = 4; i--;)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w || arr[nx][ny] > l || Find((nx << 10) + ny) == Find(cur)) continue;
			Union(x, y, nx, ny);
		}

	}
	printf("%d", ans);
}