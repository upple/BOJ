#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b)
{
	if(a>b) swap(a, b);
	if(a==0) return b;
	return GCD(b%a, a);
}

int main()
{
	int n, gcd;
	cin>>n>>gcd;
	while(--n)
	{
		int x;
		cin>>x;
		gcd=GCD(gcd, x);
	}

	set<int> ans;
	for(int i=1; i*i<=gcd; i++)
		if(gcd%i==0) ans.insert(i), ans.insert(gcd/i);

	for(int i : ans)
		cout<<i<<"\n";
}