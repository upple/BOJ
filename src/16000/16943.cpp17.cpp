#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string a;
    int b;
    cin>>a>>b;

    sort(a.rbegin(), a.rend());

    do
    {
        if(stoi(a)<b)
        {
            if(a[0]=='0') cout<<-1;
            else cout<<a;
            return 0;
        }

    }while(prev_permutation(a.begin(), a.end()));
    cout<<-1;
}