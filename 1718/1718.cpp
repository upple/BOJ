#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int main()
{
	string str, key;
	getline(cin, str);
	cin>>key;

	for(int i=0; i<str.size(); i++)
	{
		if(islower(str[i]))
		{
			int jmp=key[i%key.size()]-'a';
			str[i]=(str[i]-'a'+25-jmp)%26+'a';
		}
	}

	cout<<str;
}
