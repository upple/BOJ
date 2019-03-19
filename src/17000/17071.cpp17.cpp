#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

bool v[500001];
int n, k;

int main()
{
    cin>>n>>k;
    int speed=1;
    int cnt=0;

    queue<int> Q;
    Q.push(n);
    while(Q.size())
    {
        memset(v, 0, sizeof(v));
        for(int size=Q.size(); size--;)
        {
            int cur=Q.front();
            Q.pop();
            if(cur==k)
            {
                cout<<cnt;
                return 0;
            }
            if(cur-1>=0 && v[cur-1]==0)
            {
                Q.push(cur-1);
                v[cur-1]=1;
            }
            if(cur+1<=500000 && v[cur+1]==0)
            {
                Q.push(cur+1);
                v[cur+1]=1;
            }
            if(cur<=250000 && v[cur<<1]==0)
            {
                Q.push(cur<<1);
                v[cur<<1]=1;
            }
        }

        cnt++;
        k+=speed++;
        if(k>500000)
        {
            cout<<-1;
            return 0;
        }
    }
}