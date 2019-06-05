#include<iostream>
using namespace std;

int main()
{
    long double a, b, c;
    cin>>a>>b>>c;
    if(a==0 || b==0) cout<<(c>=0?"0":"overflow");
    else
    {
        long double d=c/b;
        if(a<=d) cout<<(unsigned long long)(a*b);
        else cout<<"overflow";
    }
    
}