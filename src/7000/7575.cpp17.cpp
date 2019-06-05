#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef unsigned long long ull;

vector<vector<ui> > codes;
ui p1[1001], p2[1001];
const ui m1=1e9+7, m2=1e9+27;

unordered_set<ull> H[100];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin>>n>>k;
    codes.resize(n);
    p1[0]=p2[0]=1;
    for(int i=1; i<=k; i++)
        p1[i]=p1[i-1]*m1, p2[i]=p2[i-1]*m2;

    for(int i=0; i<n; i++)
    {
        int c;
        cin>>c;
        codes[i].resize(c);
        for(int j=0; j<c; j++)
            cin>>codes[i][j];
    }

    ui h1, h2, r1, r2;
    ull h, r;

    for(int u=0; u<codes.size(); u++)
    {
        auto &code=codes[u];
        h1=h2=r1=r2=0;
        for(int i=0; i<k; i++)
        {
            h1=h1*m1+code[i];
            h2=h2*m2+code[i];
            r1=r1*m1+code[code.size()-i-1];
            r2=r2*m2+code[code.size()-i-1];
        }

        h=((ull)h1<<32)+h2;
        r=((ull)r1<<32)+r2;
        if(u==0 || H[u-1].find(h)!=H[u-1].end())
        {
            H[u].insert(h);
        }
        if(u==0 || H[u-1].find(r)!=H[u-1].end())
        {
            H[u].insert(r);
        }
        for(int i=k; i<code.size(); i++)
        {
            h1=(h1-p1[k-1]*code[i-k])*m1+code[i];
            h2=(h2-p2[k-1]*code[i-k])*m2+code[i];
            r1=(r1-p1[k-1]*code[code.size()-i+k-1])*m1+code[code.size()-i-1];
            r2=(r2-p2[k-1]*code[code.size()-i+k-1])*m2+code[code.size()-i-1];
            h=((ull)h1<<32)+h2;
            r=((ull)r1<<32)+r2;
            if(u==0 || H[u-1].find(h)!=H[u-1].end())
            {
                H[u].insert(h);
            }
            if(u==0 || H[u-1].find(r)!=H[u-1].end())
            {
                H[u].insert(r);
            }
        }
        
        if(H[u].empty()) break;
    }
    if(H[codes.size()-1].size()) cout<<"YES";
    else cout<<"NO";
}