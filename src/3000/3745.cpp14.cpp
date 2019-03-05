#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	while(cin>>n)
	{
		vector<int> ans;
		int x;
		cin>>x;
		ans.push_back(x);
		for(int i=1; i<n; i++)
		{
			cin>>x;
			auto it=lower_bound(ans.begin(), ans.end(), x);
			if(it==ans.end()) ans.push_back(x);
			else *it=x;
		}

		cout<<ans.size()<<"\n";
	}
}
