#include <iostream>
#include <memory.h>
using namespace std;

int c[11];
int main()
{
    int n;
    memset(c, -1, sizeof(c));
    cin>>n;
    int cnt=0;
    while(n--)
    {
        int a, b;
        cin>>a>>b;
        if(c[a]!=-1 && c[a]!=b) cnt++;
        c[a]=b;
    }

    cout<<cnt;
}