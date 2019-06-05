#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
char code[]=" ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
int main()
{
	int n;
	string a, b;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		int x;
		cin>>x;
		b+=code[x];
	}
	cin.get();
	getline(cin, a);
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	cout<<(a==b?'y':'n');
}