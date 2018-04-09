#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int num, max=0;
	cin >> num;

	int *lope = new int[num];

	for (int i = 0; i < num; i++)
		cin >> lope[i];

	sort(lope, lope + num);

	for (int i = 1; i <= num; i++)
	{
		int posible = lope[num - i] * i;
		max = max > posible ? max : posible;
	}

	cout << max << endl;
	return 0;
}