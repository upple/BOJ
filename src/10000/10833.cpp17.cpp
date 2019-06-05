#include <iostream>
using namespace std;

int main()
{
    int n, ans=0;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int a, b;
        cin>>a>>b;
        ans+=b%a;
    }

    cout<<ans;
}