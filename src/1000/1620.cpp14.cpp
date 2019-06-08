#include<iostream>
#include<string>
#include<unordered_map>
#include<cctype>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unordered_map<string, int> name;
	string number[100001];
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		string poke_name;
		cin >> poke_name;
		name[poke_name] = i;
		number[i] = poke_name;
	}
	while (m--)
	{
		string temp;
		cin >> temp;
		if (isdigit(temp[0]))
			cout << number[stoi(temp)];

		else
			cout << name[temp];

		cout << "\n";
	}
}