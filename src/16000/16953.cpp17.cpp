#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;
unordered_set<int> S;
int main()
{
    int a, b;
    cin>>a>>b;

    queue<int> Q;
    Q.push(a);
    int cnt=1;
    while(Q.size())
    {
        int size=Q.size();
        while(size--)
        {
            int cur=Q.front();
            Q.pop();

            if(cur==b)
            {
                cout<<cnt;
                return 0;
            }
            if((cur<<1)<=b && S.find(cur<<1)==S.end())
            {
                Q.push(cur<<1);
                S.insert(cur<<1);
            }

            if(cur<=b/10 && S.find(cur*10+1)==S.end())
            {
                Q.push(cur*10+1);
                S.insert(cur*10+1);
            }
        }
        cnt++;
    }

    cout<<-1;
}