#include <bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	cin>>str;
	stack<char> S;
	for(int i=0; i<str.size(); i++)
	{
		switch(str[i])
		{
			case 'A':
			if(S.size()<2 || i==str.size()-1)
			{
				cout<<"NP";
				return 0;
			}

			char a, b;
			a=S.top(), S.pop();
			b=S.top(), S.pop();
			if(a=='P' && b=='P' && str[i+1]=='P') break;
			cout<<"NP";
			return 0;
			case 'P':
			S.push('P');
		}
	}

	if(S.size()==1 && S.top()=='P')
	{
		cout<<"PPAP";
	}
	else cout<<"NP";
}