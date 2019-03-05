#include <bits/stdc++.h>
using namespace std;

int a[10];
int main()
{
    string n;
    cin>>n;
    for(char i : n)
    {
        switch(i)
        {
            case '2': case '0': case '1': case '8':
            a[i-'0']++;
            break;
            default:
            cout<<0;
            return 0;

        }
    }
    if(a[2]==a[0] && a[1]==a[8] && a[2]==a[1])
        cout<<8;
    else if(a[2] && a[0] && a[1] && a[8])
        cout<<2;
    else cout<<1;


}