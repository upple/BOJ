#include<iostream>
#include<string>

using namespace std;

int main()
{
	int rec[4];
	bool coor[100][100] = { 0, };
	int result = 0;
	for (int i = 0; i < 4; i++)
	{
		cin >> rec[0] >> rec[1] >> rec[2] >> rec[3];
		for (int j = rec[0]-1; j < rec[2]-1; j++)
		{
			for (int k = rec[1]-1; k < rec[3]-1; k++)
			{
				if (coor[j][k] == 0)
					coor[j][k] = 1, result++;
			}

		}

	}

	cout << result << endl;

	return 0;
}
