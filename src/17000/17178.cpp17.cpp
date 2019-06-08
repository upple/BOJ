#include <bits/stdc++.h>
using namespace std;

queue<int> arr;
int main()
{
	int n;
	cin>>n;
	priority_queue<int, vector<int>, greater<int> > pq;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<5; j++)
		{
			string a;
			cin>>a;
			int x=(a[0]-'A')*1000+stoi(string(a.begin()+2, a.end()));
			pq.push(x);
			arr.push(x);
		}
	}

	stack<int> S;
	while(pq.size())
	{
		if(arr.size() && pq.top()==arr.front())
		{
			pq.pop(), arr.pop();
		}
		else if(S.size() && S.top()==pq.top())
		{
			S.pop(), pq.pop();
		}
		else if(arr.size() && (S.empty() || S.top()>arr.front()))
		{
			S.push(arr.front());
			arr.pop();
		}
		else
		{
			cout<<"BAD";
			return 0;
		}
	}

	cout<<"GOOD";
}