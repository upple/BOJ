#include<iostream>
#include<string>

using namespace std;

int main()
{
	string n1, n2, result="";
	char sign;

	cin >> n1 >> sign >> n2;
	if (n2.size() > n1.size())
		swap(n2, n1);

	switch (sign)
	{
	case '+':
		for (int i = 0; i < n1.size(); i++)
		{
			if (i == 0 && n1.size() == n2.size())
				result += "2";

			else if (i == 0 || i == n1.size() - n2.size())
				result += "1";

			else
				result += "0";
				
		}
		break;

	case '*':
		result += "1";
		for (int i = 1; i < n1.size()+n2.size()-1; i++)
			result += "0";
		break;

	default:
		break;

	}

	cout << result << endl;
}