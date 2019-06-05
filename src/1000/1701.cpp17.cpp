#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull p[5001];
int main()
{
	string str;
	cin>>str;

	p[0]=1;
	for(int i=1; i<str.size(); i++)
		p[i]=p[i-1]*7;

	int l=1, r=str.size()-1;
	int ans=0;
	while(l<=r)
	{
		ull hash=0;
		int mid=l+r>>1;
		unordered_map<ull, vector<int> > M;
		for(int i=0; i<mid; i++)
			hash=hash*7+str[i];

		M[hash].push_back(1);
		bool chk=false;
		for(int i=mid; i<str.size(); i++)
		{
			hash-=p[mid-1]*str[i-mid];
			hash=hash*7+str[i];
			
			for(int s : M[hash])
			{
				for(int j=0; j<mid; j++)
				{
					if(str[s+j-1]!=str[i-mid+j+1]) break;
					if(j==mid-1) chk=true;
				}
				if(chk==true) break;
			}
			if(chk==true) break;
			M[hash].push_back(i-mid+2);
		}

		if(chk)
		{
			ans=max(ans, mid);
			l=mid+1;
		}
		else r=mid-1;
	}

	cout<<ans;
}