#include <iostream>
using namespace std;
char str[1000000];
int a, b;
int main()
{
    int n;
    cin>>n;
    cin>>str;
    for(int i=0; i<n; i++)
    {
        str[i]=='2'?a++:b++;
    }
    
    cout<<(a>b?"2":(a<b)?"e":"yee");
}