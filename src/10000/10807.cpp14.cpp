#include<iostream>

using namespace std;

int main()
{
	int num[201]={0, };
	int n, v, d;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>d, num[d+100]++;

	cin>>v;
	cout<<num[v+100]<<endl;
	return 0;
}
