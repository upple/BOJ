#include <cstdio>
#include <queue>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        pair<int, int>arr[100];
        priority_queue<int> pq;
        int n, m, count=0;
        scanf("%d %d", &n, &m);
        for(int i=0; i<n; i++)
        {
            int priority;
            scanf("%d", &priority);
            arr[i]={priority, i};
            pq.push(priority);
        }

        for(int i=0; i<n; i=(i+1)%n)
        {
            if(pq.top()==arr[i].first)
            {
                count++;
                if(arr[i].second==m)
                {
                    printf("%d\n", count);
                    break;
                }
                pq.pop();
            }
        }
    }
}
