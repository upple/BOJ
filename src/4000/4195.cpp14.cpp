#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		unordered_map<string, pair<string, int> > M;
		int n;
		string a, b;
		cin>>n;
		while(n--)
		{
			string tmp;
			cin>>a>>b;
			if(M[a].second==0)
				M[a].second++;

			if(M[b].second==0)
				M[b].second++;

			tmp=a;
			while(M[tmp].first!="")
				tmp=M[tmp].first;

			if(a!=tmp)
			{
				M[a].first=tmp;
				a=tmp;
			}

			tmp=b;
			while(M[tmp].first!="")
				tmp=M[tmp].first;

			if(b!=tmp)
			{
				M[b].first=tmp;
				b=tmp;
			}

			if(a==b)
				cout<<M[a].second<<"\n";

			else if(a<b)
			{
				M[b].first=a;
				cout<<(M[a].second+=M[b].second)<<"\n";
			}

			else
			{
				M[a].first=b;
				cout<<(M[b].second+=M[a].second)<<"\n";
			}
		}
	}

}
