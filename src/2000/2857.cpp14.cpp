#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	bool FIND=false;
	for(int i=1; i<=5; i++)
	{
		cin>>str;
		if(str.find("FBI")!=string::npos)
			FIND=true, cout<<i<<" ";
	}

	if(!FIND)
		cout<<"HE GOT AWAY!";
}
