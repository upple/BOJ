#include <iostream>

using namespace std;

int main()
{
	int seat_case[41], temp = 1, ans = 1;
	seat_case[0] = 1, seat_case[1] = 1, seat_case[2] = 2;
	for (int i = 3; i <= 40; i++)
		seat_case[i] = seat_case[i - 2] + seat_case[i - 1];

	int no_seat, no_vip;
	cin >> no_seat>>no_vip;
	while (no_vip--)
	{
		int vip;
		cin >> vip;
		ans *= seat_case[vip - temp];
		temp = vip+1;

	}

	ans *= seat_case[no_seat - temp+1];
	cout << ans << endl;
	return 0;
}