#include <bits/stdc++.h>
using namespace std;
#define INF -1

int n, dp[501][501], cost[501][501], p[501][501];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;

        memset(dp, INF, sizeof(dp));
        memset(cost, INF, sizeof(cost));
        for (int i = 1; i <= n; i++)
        {
            cin >> dp[i][i];
            cost[i][i] = 0;
            p[i][i] = i;
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j + i <= n; j++)
            {
                for (int k = p[j][j + i - 1]; k <= p[j + 1][j + i]; k++)
                {
                    if (cost[j][j + i] == INF || cost[j][j + i] > dp[j][j + i] + cost[j][k] + cost[k + 1][j + i])
                    {
                        dp[j][j + i] = dp[j][k] + dp[k + 1][j + i];
                        cost[j][j + i] = dp[j][j + i] + cost[j][k] + cost[k + 1][j + i];
                        p[j][j + i] = k;
                    }
                }
            }
        }

        cout << cost[1][n] << "\n";
    }
}