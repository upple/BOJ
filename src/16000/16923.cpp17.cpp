#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;

    s+='a';
    bool find=false;
    while(s.size() && !find)
    {
        bool chk[26]={};
        for(int i=0; i<s.size(); i++)
        {
            if(chk[s[i]-'a']==1) break;
            chk[s[i]-'a']=1;
            if(i==s.size()-1) find=true;
        }
        if(!find)
        {
            while(s.size() && s.back()=='z')
            {
                s.pop_back();
            }
            if(s.size()) s[s.size()-1]=s.back()+1;
        }

    }
    
    cout<<(s.empty()?"-1":s);
}