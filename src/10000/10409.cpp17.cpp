#include <iostream>
using namespace std;

int main()
{
    int n, t;
    cin>>n>>t;

    int sum=0;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        sum+=x;
        if(sum>t)
        {
            cout<<i;
            return 0;
        }
    }
    cout<<n;

}