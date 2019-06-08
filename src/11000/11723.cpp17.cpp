#include <iostream>
#include <string>
using namespace std;

bool arr[21];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int m;
	cin>>m;
	string cmd;
	int x;

	while(m--)
	{
		cin>>cmd;
		if(cmd=="add")
		{
			cin>>x;
			arr[x]=1;
		}
		else if(cmd=="check")
		{
			cin>>x;
			cout<<arr[x]<<"\n";
		}
		else if(cmd=="toggle")
		{
			cin>>x;
			arr[x]=!arr[x];
		}
		else if(cmd=="remove")
		{
			cin>>x;
			arr[x]=0;
		}
		else if(cmd=="all")
		{
			for(int i=1; i<=20; i++)
				arr[i]=1;
		}
		else
		{
			for(int i=1; i<=20; i++)
				arr[i]=0;
		}
	}
}