#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    cin>>a>>b;

    sort(a.begin(), a.end());

    string ans;
    if(a.size()>b.size())
    {
        cout<<-1;
        return 0;
    }
    bool find=false;
    do
    {
        if(stoi(a)<=stoi(b))
            ans=a, find=true;

        else break;
    } while (next_permutation(a.begin(), a.end()));
    
    if(ans[0]!='0' && find==true)
        cout<<stoi(ans);

    else cout<<-1;
}