#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, d, e;
    char p1, p2;
    cin>>a>>p1>>b>>p2>>c;

    switch(p1)
    {
        case '+': d=a+b; break;
        case '-': d=a-b; break;
        case '*': d=a*b; break;
        case '/': 
        if(a*b<0) d=abs(a)/abs(b)*-1;
        else d=a/b;
    }
    switch(p2)
    {
        case '+': e=b+c, d+=c; break;
        case '-': e=b-c; d-=c; break;
        case '*': e=b*c; d*=c; break;
        case '/':
        if(b*c<0) e=abs(b)/abs(c)*-1;
        else e=b/c;
        if(d*c<0) d=abs(d)/abs(c)*-1;
        else d=d/c;
    }
    switch(p1)
    {
        case '+': e=a+e; break;
        case '-': e=a-e; break;
        case '*': e=a*e; break;
        case '/': 
        if(a*e<0) e=abs(a)/abs(e)*-1;
        else e=a/e;
    }

    cout<<min(d, e)<<"\n";
    cout<<max(d, e);
}