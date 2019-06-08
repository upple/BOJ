#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<string> S;
    string str;
    int n, ans_size;
    char ans;
    cin>>n;
    while(n--)
    {
        cin>>str;
        S.insert(str);
    }

    for(auto i : S)
    {
        string temp=i;
        reverse(temp.begin(), temp.end());
        if(S.find(temp)!=S.end())
        {
            cout<<i.size()<<" "<<i[i.size()/2];
            break;
        }
    }
}
