#include<iostream>

using namespace std;

int main()
{
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	if (A + D - B - C > 0)
		cout << B + C << endl;

	else
		cout << A + D << endl;

}