#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string a, b;
	int ans=0;
	cin>>a>>b;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	auto pa=a.begin(), pb=b.begin();
	while(pa!=a.end()|| pb!=b.end())
	{
		if(pa==a.end())
			pb++, ans++;

		else if(pb==b.end())
			pa++, ans++;

		else
		{
			if(*pa>*pb)
				pb++, ans++;

			else if(*pa<*pb)
				pa++, ans++;

			else
				pa++, pb++;
		}
	}
	cout<<ans;
}
