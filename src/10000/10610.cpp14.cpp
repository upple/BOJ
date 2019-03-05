#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string num;
    int sum=0;
    cin>>num;
    for(int i=0; i<num.size(); i++)
        sum+=num[i]-'0';

    if(num.find("0")==-1 || sum%3!=0)
        cout<<"-1";

    else
    {
        sort(num.begin(), num.end());
        reverse(num.begin(), num.end());

        cout<<num;
    }

    return 0;
}