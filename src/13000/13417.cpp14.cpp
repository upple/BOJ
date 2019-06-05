#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t;
	cin>> t;
	while(t--)
	{
		int n;
		string ans, temp;
		cin>>n>>ans;
		for(int i=1; i<n; i++)
		{
			cin>>temp;
			if(ans[0]>=temp[0])
				ans=temp+ans;

			else
				ans+=temp;
		}

		cout<<ans<<endl;
	}
}
