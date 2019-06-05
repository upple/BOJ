#include <cstdio>
using namespace std;

int main()
{
    long long dp[68]={1, 1, 2, 4,};
    int t, pos=4;
    scanf("%d", &t);

    while(t--)
    {
        int n;
        scanf("%d", &n);

        for(pos; pos<=n; pos++)
            dp[pos]=dp[pos-1]+dp[pos-2]+dp[pos-3]+dp[pos-4];

        printf("%lld\n", dp[n]);
    }
}
