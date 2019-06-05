#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	int n, m;
	cin>>n>>m;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			int r, g, b;
			cin>>r>>g>>b;

			int result = 2126*r+7152*g+722*b;
			if(result<510000) cout<<'#';
			else if(result<1020000) cout<<'o';
			else if(result<1530000) cout<<'+';
			else if(result<2040000) cout<<'-';
			else cout<<'.';
		}
		cout<<'\n';
	}
}