#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n, cur, cur_max=0, ans=0, count=0;
    scanf("%d", &n);
    
    for(int i=0; i<n; i++)
    {
        scanf("%d", &cur);
        if(cur_max<cur)
        {
            cur_max=cur;
            ans=max(ans, count);
            count=0;
            continue;
        }
        count++;
    }
    ans=max(ans, count);
    
    printf("%d", ans);
}