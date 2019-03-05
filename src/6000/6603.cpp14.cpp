#include <iostream>
#include <string>
using namespace std;
int k, arr[13];
string ans="";
void dfs(int count, int p)
{
	if(p==k)
		return;

	for(int i=p; i<k; i++)
	{
		if(count==6)
			cout<<ans<<arr[i]<<"\n";

		else
		{
			string temp=ans;
			ans+=to_string(arr[i])+" ", dfs(count+1, i+1);
			ans=temp;
		}
	}

}
int main()
{
	ios_base::sync_with_stdio(false);
	while(1)
	{
		cin>>k;
		if(!k)
			return 0;

		for(int i=0; i<k; i++)
			cin>>arr[i];

		dfs(1, 0);
		cout<<"\n";
	}
}
