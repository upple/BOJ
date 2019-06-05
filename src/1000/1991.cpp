#include<iostream>
#include<map>
using namespace std;

map<char, char> l, r;

void pre(char k)
{
	if (k == '.')
		return;
	cout << k;
	pre(l[k]), pre(r[k]);
}
void mid(char k)
{
	if (k == '.')
		return;
	mid(l[k]);
	cout << k;
	mid(r[k]);
}
void post(char k)
{
	if (k == '.')
		return;
	post(l[k]), post(r[k]);
	cout << k;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char a, b, c;
		cin >> a >> b >> c;
		l[a] = b, r[a] = c;
	}

	pre('A'); cout << endl;
	mid('A'); cout << endl;
	post('A'); cout << endl;
	return 0;
}