#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
int main()
{
    int a, b, n, w, cnt=0;
    cin>>a>>b>>n>>w;

    for(int i=1; i<n; i++)
    {
        if(i*a+(n-i)*b==w) ans.push_back(i);
    }

    if(ans.size()==1) cout<<ans.front()<< ' '<<n-ans.front();
    else cout<<-1;
}