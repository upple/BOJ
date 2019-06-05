#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

map<char, int> M[50];
int main()
{
	int n, m, cnt=0;
	string dna, ans;
	cin>>n>>m;

	for(int i=0; i<n; i++)
	{
		cin>>dna;
		for(int j=0; j<m; j++)
		{
			M[j][dna[j]]++;
		}
	}

	for(int i=0; i<m; i++)
	{
		int big=0;
		char ch;
		for(auto &j : M[i])
		{
			if(big<j.second)
				ch=j.first, big=j.second;
		}

		ans+=ch, cnt+=n-big;
	}

	cout<<ans<<"\n"<<cnt;
}
