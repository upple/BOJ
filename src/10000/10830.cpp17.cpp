#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct matrix
{
	vector<vector<int> > a;
	int size;
	matrix(int n): size(n)
	{
		a.assign(n, vector<int>(n, 0));
	}

	matrix operator *(matrix &x)
	{
		matrix ret(size);
		for(int i=0; i<size; i++)
		{
			for(int j=0; j<size; j++)
			{
				for(int k=0; k<size; k++)
				{
					ret.a[i][j]=(ret.a[i][j]+(a[i][k]*x.a[k][j]))%1000;
				}
			}
		}

		return ret;
	}

	matrix & operator =(matrix x)
	{
		for(int i=0; i<size; i++)
		{
			for(int j=0; j<size; j++)
			{
				a[i][j]=x.a[i][j];
			}
		}
		return *this;
	}
};
int main()
{
	int n;
	ll b;
	cin>>n>>b;
	matrix mat(n), ans(n);

	for(int i=0; i<n; i++)
	{
		ans.a[i][i]=1;
		for(int j=0; j<n; j++)
		{
			cin>>mat.a[i][j];
		}
	}

	while(b)
	{
		if(b%2)
		{
			ans=ans*mat;
		}
		mat=mat*mat;
		b>>=1;
	}

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<ans.a[i][j]<<' ';
		}

		cout<<"\n";
	}
}