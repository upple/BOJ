#include <bits/stdc++.h>
using namespace std;

int v[2][500001];
int main()
{
    int a, b;
    cin>>a>>b;

    memset(v, -1, sizeof(v));

    queue<int> Q;
    Q.push(a);
    v[0][a]=0;
    bool o=0;
    while(Q.size())
    {
        for(int size=Q.size(); size--;)
        {    
            int cur=Q.front();
            Q.pop();
            if(cur>0 && v[!o][cur-1]==-1)
            {
                Q.push(cur-1);
                v[!o][cur-1]=v[o][cur]+1;
            }
            if(cur<500000 && v[!o][cur+1]==-1)
            {
                Q.push(cur+1);
                v[!o][cur+1]=v[o][cur]+1;
            }
            if(cur<=250000 && v[!o][cur<<1]==-1)
            {
                Q.push(cur<<1);
                v[!o][cur<<1]=v[o][cur]+1;
            }
        }
        o=!o;
        
    }

    for(int i=1; b<=500000; i++)
    {
        if(v[(i-1)%2][b]!=-1)
        {
            if(v[(i+1)%2][b]<i && v[(i+1)%2][b]%2==(i-1)%2)
            {
                cout<<i-1;
                return 0;
            }
        }
        b+=i;
    }

    cout<<-1;
}