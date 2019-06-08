#include <bits/stdc++.h>
using namespace std;

bool v[100001];
int main()
{
    int n, t, g;
    cin>>n>>t>>g;
    queue<int> Q;
    Q.push(n);
    v[n]=1;
    int cnt=0;
    while(Q.size())
    {
        int size=Q.size();
        while(size--)
        {
            int cur=Q.front();
            Q.pop();

            if(cur==g)
            {
                cout<<cnt;
                return 0;
            }
            if(cur+1<100000 && v[cur+1]==0)
            {
                v[cur+1]=1;
                Q.push(cur+1);
            }
            if(cur*2<100000)
            {
                int next = cur*2-pow(10, int(floor(log10(cur*2))));
                if(v[next]==0)
                {
                    v[next]=1;
                    Q.push(next);
                }
            }
        }
        if(++cnt>t)
        {
            cout<<"ANG";
            return 0;
        }
        
    }

    cout<<"ANG";
}