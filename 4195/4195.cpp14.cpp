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
		string s[2];
		cin>>n;
		while(n--)
		{
			string tmp;
			cin>>s[0]>>s[1];

			for(int i=0; i<2; i++)
			{
				if(M[s[i]].second==0)
					M[s[i]].second++;

				tmp=s[i];
				while(M[tmp].first!="")
					tmp=M[tmp].first;

				if(s[i]!=tmp)
				{
					M[s[i]].first=tmp;
					s[i]=tmp;
				}

			}

			string &a=s[0], &b=s[1];
			if(s[0]==s[1])
				cout<<M[s[0]].second<<"\n";

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
