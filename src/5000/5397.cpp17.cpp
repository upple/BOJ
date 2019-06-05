#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin>>t;
	while(t--)
	{
		stack<char> f, b;
		string str;
		cin>>str;
		for(char ch : str)
		{
			switch(ch)
			{
				case '<':
				if(f.size()) b.push(f.top()), f.pop();
				break;
				case '>':
				if(b.size()) f.push(b.top()), b.pop();
				break;
				case '-':
				if(f.size()) f.pop();
				break;
				default:
				f.push(ch);
			}
		}

		while(f.size())
		{
			b.push(f.top());
			f.pop();
		}
		while(b.size())
		{
			cout<<b.top();
			b.pop();
		}
		cout<<'\n';
	}

}