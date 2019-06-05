#include <bits/stdc++.h>
using namespace std;

string ans;
int n;
bool solve(int p)
{
	if(p==n)
	{
		cout<<ans;
		return true;
	}

	for(char i='1'; i<='3'; i++)
	{
		ans.push_back(i);
		bool chk=true;
		for(int j=1; j<=ans.size()/2; j++)
		{
			chk=false;
			for(int k=0; k<j; k++)
			{
				if(ans[ans.size()-j-k-1]!=ans[ans.size()-k-1])
				{
					chk=true;
					break;
				}
			}
			if(chk==false) break;
		}
		if(chk && solve(p+1)) return true;
		ans.pop_back();
		
	}
	return false;
}
int main()
{
	cin>>n;

	solve(0);
}