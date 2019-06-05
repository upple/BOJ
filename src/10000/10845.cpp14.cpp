#include<iostream>
#include<string>
#include<queue>

using namespace std;

int main()
{
	queue<int> Queue;
	string command;
	int no_case, num;
	cin >> no_case;
	while (no_case--)
	{
		cin >> command;

		if (command == "push")
		{
			cin >> num;
			Queue.push(num);
		}

		else if (command == "pop")
		{
			if (Queue.empty())
				cout << -1 << endl;

			else
			{
				cout << Queue.front() << endl;
				Queue.pop();
			}

		}

		else if (command == "size")
			cout << Queue.size() << endl;

		else if (command == "empty")
			cout << Queue.empty() << endl;

		else if (command == "front")
		{
			if (Queue.empty())
				cout << -1 << endl;

			else
				cout << Queue.front() << endl;
		}

		else
		{
			if (Queue.empty())
				cout << -1 << endl;

			else
				cout << Queue.back() << endl;
		}

	}

	return 0;
}
