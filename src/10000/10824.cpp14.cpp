#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main()
{
	string a, b, c, d;
	long long ab, cd;

	cin >> a >> b >> c >> d;
	ab = (long long)stoi(a)*(long long)pow(10, b.size())+(long long)stoi(b);
	cd = (long long)stoi(c)*(long long)pow(10, d.size()) + (long long)stoi(d);

	cout << ab + cd << endl;
}