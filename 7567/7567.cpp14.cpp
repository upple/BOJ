#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	int ans=10;
	cin>>str;
	for(int i=1; i<str.size(); i++)
	{
		if(str[i-1]==str[i])
			ans+=5;

		else
			ans+=10;
	}

	cout<<ans<<endl;
	return 0;
}
