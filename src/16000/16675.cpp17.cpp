#include <bits/stdc++.h>
using namespace std;
set<pair<char, char> > S;

int main()
{
    S.insert({'P', 'R'});
    S.insert({'S', 'P'});
    S.insert({'R', 'S'});
    char ml, mr, tl, tr;
    cin>>ml>>mr>>tl>>tr;

    if(ml==mr && tl==tr)
    {
        if(ml==tl) cout<<"?";
        else if(S.find({ml, tl})!=S.end()) cout<<"MS";
        else if(S.find({tl, ml})!=S.end()) cout<<"TK";
        else cout<<"?";
    }
    else if(ml==mr)
    {
        if(S.find({tl, ml})!=S.end()) cout<<"TK";
        else if(S.find({tr, ml})!=S.end()) cout<<"TK";
        else cout<<"?";
    }
    else if(tl==tr)
    {
        if(S.find({ml, tl})!=S.end()) cout<<"MS";
        else if(S.find({mr, tl})!=S.end()) cout<<"MS";
        else cout<<"?";
    }
    else
    {
        cout<<"?";
    }
}