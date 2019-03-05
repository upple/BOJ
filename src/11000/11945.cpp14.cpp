#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	string fish;
	for (int i = 0; i < n; i++)
	{
		cin>>fish;
        reverse(fish.begin(), fish.end());
        cout<<fish<<endl;
	}

	return 0;
}