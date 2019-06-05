#include <bits/stdc++.h>
using namespace std;

int adj[101];
bool v[101];
int main()
{
    int n, m;
    cin>>n>>m;

    for(int i=n+m; i--;)
    {
        int a, b;
        cin>>a>>b;
        adj[a]=b;
    }

    queue<int> Q;
    v[1]=1;
    Q.push(1);
    int ans=0;
    while(Q.size())
    {
        for(int size=Q.size(); size--;)
        {
            int cur=Q.front();
            Q.pop();

            if(cur==100)
            {
                cout<<ans;
                return 0;
            }

            for(int i=1; i<=6; i++)
            {
                int next=cur+i;
                if(next>100) break;
                if(adj[next]!=0) next=adj[next];

                if(!v[next]) Q.push(next), v[next]=1;
            }
        }
        ans++;
    }

    cout<<ans;
}