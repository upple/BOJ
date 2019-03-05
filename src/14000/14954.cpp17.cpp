#include <bits/stdc++.h>
using namespace std;
unordered_set <int> S;
int main()
{
	int n, cur;
	cin>>n;
	cur=n;
	S.insert(n);
	while(cur!=1)
	{
		int next=0;
		while(cur)
		{
			next+=int(pow(cur%10, 2));
			cur/=10;
		}
		if(S.find(next)!=S.end())
		{
			cout<<"UNHAPPY";
			return 0;
		}
		S.insert(next);
		cur=next;
	}
	cout<<"HAPPY";
}