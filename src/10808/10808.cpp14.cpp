#include<iostream>
#include<string>

using namespace std;

int main()
{
	int num[26]={0, };
	string str;
	cin>>str;

	for(int i=0; i<str.size(); i++)
		num[str.at(i)-'a']++;

	for(int i=0; i<26; i++)
		cout<<num[i]<<" ";

	cout<<endl;
	return 0;
}
