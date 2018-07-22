#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int n, k, ans=0;
    scanf("%d %d", &n, &k);
    vector<vector<int> > dp(n, vector<int>(k+1, 0));
    vector<int> cost(n);

    for(int i=0; i<n; i++)
        scanf("%d", &cost[i]);

    dp[0][0]=1;
    for(int i=1; i<=k; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i-cost[j]<0)
                continue;

            for(int s=0; s<=j; s++)
                dp[j][i]+=dp[s][i-cost[j]];
        }
    }

    for(int i=0; i<n; i++)
        ans+=dp[i][k];

    printf("%d", ans);
}
