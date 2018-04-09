#include<iostream>
#include<string>

using namespace std;

int main()
{
	string num;
	int count = 0;
	cin >> num;

	for (int i = 0; i < num.size(); i++)
		if (i == num.size() - 1 || num.at(i + 1) == ',')
			count++;

	cout << count << endl;
	return 0;
}