#include<iostream>
#include<queue>

using namespace std;

int main()
{
	int num;
	queue<int> deck, out;

	cin >> num;
	for (int i = 1; i <= num; i++)
		deck.push(i);

	out.push(deck.front());
	deck.pop();
	while (!(deck.empty()))
	{
		deck.push(deck.front());
		deck.pop();
		out.push(deck.front());
		deck.pop();
	}

	while(!(out.empty()))
	{
		cout << out.front() << " ";
		out.pop();
	}

	cout << endl;
	return 0;
}