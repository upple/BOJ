#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;
struct state { int s, z; };
int d[] = { -1, 1, -3, 3 };

int main()
{
	string t;
	int s, g = 123456780;
	int sz, cnt = 0;
	for (int i = 0; i < 9; i++)
	{
		t += cin.get();
		if (t.back() == '0')
			sz = i;

		cin.get();
	}
	
	s = stoi(t);
	queue<state> Q;
	unordered_set<int> v;
	Q.push({ s, sz });
	v.insert(s);
	while (Q.size())
	{
		int size = Q.size();
		while (size--)
		{
			int tmp = Q.front().s;
			int z = Q.front().z;
			Q.pop();

			if (tmp == g)
			{
				cout << cnt;
				return 0;
			}

			string cur = to_string(tmp);
			if (cur.size() == 8)
				cur = "0" + cur;
			for (int i = 0; i < 4; i++)
			{
				int nz = z + d[i];
				if (nz >= 0 && nz < 9 && (nz / 3 == z / 3 || nz % 3 == z % 3))
				{
					swap(cur[nz], cur[z]);
					tmp = stoi(cur);
					if (v.find(tmp) == v.end())
					{
						Q.push({ tmp, nz });
						v.insert(tmp);
					}
					swap(cur[nz], cur[z]);
				}
			}
		}
		cnt++;
	}

	cout << -1;
}