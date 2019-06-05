#include<iostream>
#include<string>
#include<queue>
using namespace std;
int main()
{

	char M[3];
	queue<pair<int, int> > Q;
	M[0] = 'B', M[1] = 'L', M[2] = 'D';
	int n, count = 0, time = 0;
	bool check[1500][1500] = {};
	string str;
	cin >> n >> str;
	Q.push({ 0, str.size() - 1 });
	Q.push({ -1, -1 });
	while (!Q.empty())
	{
		int s = Q.front().first, e = Q.front().second;
		Q.pop();
		if (s == -1)
		{
			if (Q.empty())
				break;

			count++, time = (time + 1) % 3, Q.push({ -1, -1 });
			continue;
		}

		if (s>e)
			break;

		if (str[s] == M[time] && !check[s + 1][e])
			check[s + 1][e] = true, Q.push({ s + 1, e });

		if (str[e] == M[time] && !check[s][e - 1])
			check[s][e - 1] = true, Q.push({ s, e - 1 });
	}

	cout << count;
}
