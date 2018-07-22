#include<iostream>
#include<string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	int n, cossor;
	char cmd;
	cin >> str >> n;
	cossor = str.size();
	while (n--)
	{
		cin >> cmd;
		switch (cmd)
		{
		case 'L':
			if (cossor)
				cossor--;
			break;

		case 'D':
			if (cossor<str.size())
				cossor++;
			break;

		case 'B':
			if (cossor)
				str.erase(str.begin() + (cossor--) - 1);
			break;

		case 'P':
			string temp;
			cin >> temp;
			str.insert(cossor++, temp);

		}
	}

	cout << str << endl;
	return 0;
}