#include<iostream>
#include<string>

using namespace std;

int main()
{
	string shuffle;
	bool cup[3] = { 1, 0, 0 };
	cin >> shuffle;
	for (int i = 0; i<shuffle.size(); i++)
		switch ((int)(shuffle.at(i)))
		{
		case 'A':
			swap(cup[0], cup[1]);
			break;
		case 'B':
			swap(cup[1], cup[2]);
			break;
		case 'C':
			swap(cup[0], cup[2]);
			break;
		default:
			break;
		}

	for (int i = 0; i < 3; i++)
		if (cup[i])
		{
			cout << i + 1 << endl;
			break;
		}

	return 0;
}
