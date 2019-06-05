#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	queue<int> Q;
	int n, m, num;
	cin >> n >> m;
	while (n--)
	{
		cin >> num;
		Q.push(num);
	}
	
	while (m--)
	{
		cin >> num;
		while(Q.size() && Q.front() <= num)
			cout << Q.front() << " ", Q.pop();

		cout << num << " ";
	}

	while (Q.size())
		cout << Q.front() << " ", Q.pop();
}