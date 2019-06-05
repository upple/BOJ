#include <bits/stdc++.h>
typedef unsigned long long ull;
using namespace std;
const ull MUL=1e9+9;
ull p=1;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    string str;
    cin>>n>>m>>str;

    ull hash='I';
    
    for(int i=0; i<n; i++)
    {
        hash=((hash*MUL)+'O')*MUL+'I';
    }

    int len=n*2+1;
    for(int i=1; i<len; i++)
        p*=MUL;

    ull cur=0;
    for(int i=0; i<len; i++)
    {
        cur=(cur*MUL)+str[i];
    }

    int cnt=0;
    for(int i=len; i<m; i++)
    {
        if(cur==hash) cnt++;
        cur=(cur-str[i-len]*p)*MUL+str[i];
    }
    if(cur==hash) cnt++;
    cout<<cnt;
}