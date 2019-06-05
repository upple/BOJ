#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	vector<int>arr;
	int no_case;

	cin>>no_case;
	while(no_case--)
	{
		string command;
		int num;
		cin>>command;
		if(command=="push")
		{
			cin>>num;
			arr.push_back(num);
		}

		else if(command=="pop")
		{
			if(arr.empty())
				cout<<-1<<endl;

			else
				cout<<arr.back()<<endl, arr.pop_back();

		}

		else if(command=="size")
			cout<<arr.size()<<endl;

		else if(command=="empty")
			cout<<arr.empty()<<endl;

		else if(command=="top")
		{
			if(arr.empty())
				cout<<-1<<endl;

			else
				cout<<arr.back()<<endl;
		}
	}

	return 0;
}
