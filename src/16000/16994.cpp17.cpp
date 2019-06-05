#include <iostream>
#include <string>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
string str;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>str;
    crope r;
    for(char i : str)
        r.push_back(i);

    int n;
    cin>>n;
    while(n--)
    {
        int a, b, c;
        cin>>a;
        if(a==1)
        {
            cin>>b>>c;
            crope tmp=r.substr(b, c-b+1);
            r.erase(b, c-b+1);
            r.insert(r.mutable_begin(), tmp);
        }
        else if(a==2)
        {
            cin>>b>>c;
            crope tmp=r.substr(b, c-b+1);
            r.erase(b, c-b+1);
            r.insert(r.mutable_end(), tmp);
        }

        else
        {
            cin>>b;
            cout<<r[b]<<'\n';
        }
    }


}