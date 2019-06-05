#include <iostream>
#include <string>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str, boom, ans;
    cin>>str>>boom;
    int b_size=boom.size();
    for(char ch : str)
    {
        ans.push_back(ch);
        while(ans.size()>=b_size && ans.substr(ans.size()-b_size, ans.size())==boom)
            ans.erase(ans.end()-b_size, ans.end());
    }
    cout<<(ans==""?"FRULA":ans);
}
