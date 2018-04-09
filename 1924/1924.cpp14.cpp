#include <iostream>
#include <string>

using namespace std;
int main()
{
	int m, d, ans=0;
	string day[7] = {"SUN" , "MON", "TUE", "WED", "THU", "FRI", "SAT"};
	cin>>m>>d;

	for (int i = 1; i < m; i++)
	{
		switch (i)
		{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			ans += 31;
			break;

		case 4: case 6: case 9: case 11:
			ans += 30;
			break;

		case 2:
			ans += 28;
		}

	}
	ans += d;

	cout << day[(ans % 7)] << endl;
	return 0;
}