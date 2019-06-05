#include <iostream>
#include <string>
#include <map>
#include <cctype>
using namespace std;

string str;
int i;
map<char, int> k;


int func()
{
    int temp=0;
    for(i; i<str.size(); i++)
    {
        char pos=str.at(i);
        if(pos=='(')
            i++, temp+=func();

        else if(pos==')')
        {
            if(i==str.size()-1 || !isdigit(str.at(i+1)))
            {
                return temp;
            }

        }
        else if(pos>='2' && pos<='9')
        {
            if(str.at(i-1)==')')
                return temp*(pos-'0');

            else
                temp-=k[str.at(i-1)], temp+=k[str.at(i-1)]*(pos-'0');
        }

        else
            temp+=k[pos];
    }

    return temp;
}
int main()
{
    int ans=0;
    k['H']=1;
    k['C']=12;
    k['O']=16;
    cin>>str;
    ans+=func();
    printf("%d\n", ans);
}
