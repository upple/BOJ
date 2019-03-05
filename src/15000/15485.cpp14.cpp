#include <iostream>
#include <string>
#define MOD 1000000007
using namespace std;

string str;
int a, b, c, na, nb, nc;
int main()
{
    cin>>str;
    for(char cur : str)
    {
        na=a, nb=b, nc=c;
        switch(cur)
        {
            case 'a':
            na=(a+a+1)%MOD; break;
            case 'b':
            nb=((b+b)%MOD+a)%MOD; break;
            case 'c':
            nc=((c+c)%MOD+b)%MOD;
        }

        a=na, b=nb, c=nc;
    }

    cout<<c;
}