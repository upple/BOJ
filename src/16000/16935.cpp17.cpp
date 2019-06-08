#include <bits/stdc++.h>
using namespace std;

int n, m, r;
vector<vector<int> > arr(100, vector<int>(100)), result(100, vector<int>(100));
vector<vector<int> > *a=&arr, *b=&result;
const int px[4]={0, 0, 1, 1}, py[4]={0, 1, 1, 0};
int cnt_1, cnt_2, cnt_3, cnt_5;

void func5(int s, int e)
{
	for(int i=0; i<n/2; i++)
	{
		for(int j=0; j<m/2; j++)
		{
			(*b)[i+px[e]*n/2][j+py[e]*m/2]=(*a)[i+px[s]*n/2][j+py[s]*m/2];
		}
	}
}

void rotate()
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			(*b)[j][n-i-1]=(*a)[i][j];
		}
	}
	swap(a, b);
	swap(n, m);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m>>r;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m ;j++)
		{
			cin>>arr[i][j];
		}
	}

	while(r--)
	{
		int x;
		cin>>x;
		switch(x)
		{
			case 1: cnt_1++; break;
			case 2: cnt_2++; break;
			
			case 3: 
			if((cnt_1+cnt_2)%2) cnt_3+=3;
			else cnt_3++; break;

			case 4: 
			if((cnt_1+cnt_2)%2) cnt_3++;
			else cnt_3+=3; break;

			case 5: 
			if((cnt_1+cnt_2)%2) cnt_5+=3;
			else cnt_5++; break;

			case 6: 
			if((cnt_1+cnt_2)%2) cnt_5++;
			else cnt_5+=3; break;
		}

	}

	cnt_1%=2, cnt_2%=2, cnt_3%=4, cnt_5%=4;
	for(int i=0; i<4; i++)
		func5(i, (i+cnt_5)%4);

	swap(a, b);
	for(int i=0; i<cnt_3; i++)
		rotate();

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cout<<(*a)[(cnt_1?n-1-i:i)][(cnt_2?m-1-j:j)]<<' ';
		}
		cout<<'\n';
	}
}