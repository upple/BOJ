#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string & a, string & b)
{
	if(a.size()!=b.size())
		return a.size()<b.size();

	return a<b;
}
int main()
{
	int n;
	string str;
	vector<string> V;
	scanf("%d", &n);
	while(cin>>str)
	{
		int cur=-1;
		for(int i=0; str[i]; i++)
		{
			if(cur==-1 && isdigit(str[i]-1))
			{
				cur=i;
			}

			else if(cur!=-1 && islower(str[i]))
			{
				V.push_back(str.substr(cur, i-cur));
				cur=-1;
			}

			else if(cur==-1 && islower(str[i]))
			{
				if(i!=0 && str[i-1]=='0')
					V.push_back("0");
			}

		}

		if(cur!=-1)
			V.push_back(str.substr(cur, str.size()-cur));

		else if(str.back()=='0')
			V.push_back("0");
	}

	sort(V.begin(), V.end(), cmp);
	for(auto &i : V)
	{
		cout<<i<<"\n";
	}
}
