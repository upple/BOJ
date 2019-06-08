#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<int> mul;
int sum=0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>q;
    mul.assign(n, 1);
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        for(int j=0; j<4; j++)
        {
            mul[(i+j)%n]*=x;
        }
    }

    for(int i=0; i<n; i++)
        sum+=mul[i];

    while(q--)
    {
        int x;
        cin>>x;
        x--;
        for(int i=0; i<4; i++)
        {
            sum-=mul[(x+i)%n]<<1;
            mul[(x+i)%n]*=-1;
        }
        cout<<sum<<'\n';
    }
}