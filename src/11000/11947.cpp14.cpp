#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

int main()
{
	int no_case;
	cin >> no_case;

	for (int i = 0; i<no_case; i++)
	{
		int size = 0;
		long long num, temp, love, reverse;

		cin >> num;
		temp = num;
		while(temp/10)
		{
			temp /= 10;
			size++;
		}

		if (temp >= 5)
			num = 5*(long long)pow(10, size);

		reverse = (long long)pow(10, size + 1) - num - 1;
		love = num*reverse;
		
		cout << love << endl;

	}

	return 0;
}
