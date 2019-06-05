#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[3], b[3];
    for(int i=0; i<3; i++)
    {
        cin>>a[i]>>b[i];
    }

    int n=100;
    for(int i=0; i<100; i++)
    {
        int f=min(b[(i+1)%3]+b[i%3], a[(i+1)%3])-b[(i+1)%3];
        b[i%3]-=f;
        b[(i+1)%3]+=f;
    }

    cout<<b[0]<<'\n'<<b[1]<<'\n'<<b[2];
}