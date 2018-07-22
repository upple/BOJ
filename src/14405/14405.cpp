#include <iostream>
#include <string>
using namespace std;

int main()
{
	string pikachu;
	cin >> pikachu;

	for (int i = 0; i < pikachu.size(); i++)
	{
		switch (pikachu[i])
		{
		case 'p':
			if (i + 2 > pikachu.size() || pikachu.substr(i, 2) != "pi")
				goto fail;
			
			i ++; break;
		case 'k':
			if (i + 2 > pikachu.size() || pikachu.substr(i, 2) != "ka")
				goto fail;
			i ++; break;
		case 'c':
			if (i + 3 > pikachu.size() || pikachu.substr(i, 3) != "chu")
				goto fail;
			i += 2; break;

		default: goto fail;
		}
	}

	cout << "YES";
	return 0;
fail: cout << "NO";
}