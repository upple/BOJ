#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string str;
    cin>>str;
    string rvs=str;
    reverse(rvs.begin(), rvs.end());
    cout<<(str==rvs?1:0);
}
