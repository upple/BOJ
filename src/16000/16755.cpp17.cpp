#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin>>str;
    int state=0, ans=0;
    for(char i : str)
    {
        switch(state)
        {
            case 0:
            if(i=='H') state=1; break;
            case 1:
            if(i=='O') state=2; break;
            case 2:
            if(i=='N') state=3; break;
            case 3:
            if(i=='I') state=0, ans++;
        }
    }

    cout<<ans;
}