#include <iostream>
#include <stack>
using namespace std;

int n, k, cnt;
stack<int> S;

bool solve(int x)
{
	if(x<0) return false;
	if(x==0) return k== ++cnt;

	for(int i=1; i<=3; i++)
	{
		if(solve(x-i))
		{
			S.push(i);
			return true;
		}
	}

	return false;
}
int main()
{
	cin>>n>>k;
	if(!solve(n))
	{
		cout<<-1;
		return 0;
	}

	while(1)
	{
		cout<<S.top();
		S.pop();
		if(S.empty()) break;
		cout<<"+";
	}
}