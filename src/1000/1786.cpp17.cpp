#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
vector<int> ans;
const ull mul=2292967;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string t, p;
    getline(cin, t);
    getline(cin, p);
    
    ull m=1;
    ull hash=0, test=0;
    for(int i=0; i<p.size(); i++)
    {
        hash=hash*mul+p[i];
        test=test*mul+t[i];
        if(i) m*=mul;
    }

    for(int i=p.size(); i<t.size(); i++)
    {
        if(hash==test)
        {
            ans.push_back(i-p.size()+1);
        }

        test=(test-m*t[i-p.size()])*mul+t[i];
    }

    if(test==hash) ans.push_back(t.size()-p.size()+1);
    cout<<ans.size()<<"\n";
    for(int i : ans)
    {
        cout<<i<<' ';
    }
}