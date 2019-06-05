#include<iostream>
#include<deque>
#include<string>

using namespace std;

int main()
{
	deque<int> Deque;
	int temp, no_case;
	string operater;
	cin>>no_case;

	while(no_case--)
	{
		cin>>operater;

		if(operater=="push_front")
		{
			cin>>temp;
			Deque.push_front(temp);
		}

		else if(operater=="push_back")
		{
			cin>>temp;
			Deque.push_back(temp);
		}

		else if(operater=="pop_front")
		{
			if(Deque.empty())
			{
				cout<<-1<<endl;
				continue;
			}

			cout<<Deque.front()<<endl;
			Deque.pop_front();
		}

		else if(operater=="pop_back")
		{
			if(Deque.empty())
			{
				cout<<-1<<endl;
				continue;
			}

			cout<<Deque.back()<<endl;
			Deque.pop_back();
		}

		else if(operater=="size")
			cout<<Deque.size()<<endl;

		else if(operater=="empty")
			cout<<Deque.empty()<<endl;

		else if(operater=="front")
		{
			if(Deque.empty())
			{
				cout<<-1<<endl;
				continue;
			}

			cout<<Deque.front()<<endl;
		}


		else if(operater=="back")
		{
			if(Deque.empty())
			{
				cout<<-1<<endl;
				continue;
			}

			cout<<Deque.back()<<endl;
		}

	}

	return 0;
}
