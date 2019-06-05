#include<iostream>
using namespace std;
int main()
{
    int l, a, b, c, d;
    cin>>l>>a>>b>>c>>d;
    a=a/c+(a%c>0), b=b/d+(b%d>0);
    cout<<l-(a>b?a:b);
}
