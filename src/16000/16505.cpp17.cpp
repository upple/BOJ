#include <iostream>
#include <cmath>
using namespace std;

char arr[1024][1024];
void solve(int s, int x, int y)
{
	if(s==0)
	{
		arr[x][y]='*';
		return;
	}

	s>>=1;
	solve(s, x, y);
	solve(s, x+s, y);
	solve(s, x, y+s);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	n=1<<n;

	solve(n, 0, 0);

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n-i; j++)
		{
			cout<<(arr[i][j]=='*'?'*':' ');
		}

		cout<<"\n";
	}
}