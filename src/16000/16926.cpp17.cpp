#include <bits/stdc++.h>
using namespace std;

int n, m, r;
int arr[300][300];
vector<int> tmp[150];
vector<int> X[150], Y[150];

void func(int l)
{
	for(int i=l; i<n-l-1; i++)
	{
		tmp[l].push_back(arr[i][l]);
		X[l].push_back(i);
		Y[l].push_back(l);
	}
	for(int i=l; i<m-l-1; i++)
	{
		tmp[l].push_back(arr[n-l-1][i]);
		X[l].push_back(n-l-1);
		Y[l].push_back(i);
	}
	for(int i=n-l-1; i>l; i--)
	{
		tmp[l].push_back(arr[i][m-l-1]);
		X[l].push_back(i);
		Y[l].push_back(m-l-1);
	}
	for(int i=m-l-1; i>l; i--)
	{
		tmp[l].push_back(arr[l][i]);
		X[l].push_back(l);
		Y[l].push_back(i);
	}
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	cin>>n>>m>>r;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cin>>arr[i][j];
		}
	}

	for(int i=0; i<min(n, m)/2; i++)
	{
		func(i);
		int t=r%tmp[i].size();
		for(int j=0; j<tmp[i].size(); j++)
		{
			arr[X[i][(j+t)%tmp[i].size()]][Y[i][(j+t)%tmp[i].size()]]=tmp[i][j];
		}
	}

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cout<<arr[i][j]<<' ';
		}
		cout<<"\n";
	}

}