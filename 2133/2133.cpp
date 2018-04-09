#include<cstdio>
#include<vector>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);

    if(n%2)
    {
        printf("0");
        return 0;
    }
    n/=2;
    vector<int> arr(n+1, 2), dp(n+1, 2);
    dp[1]=arr[1]=3;
    for(int i=2; i<=n; i++)
        for(int j=1; j<i; j++)
            dp[i]+=dp[j]*arr[i-j];

    printf("%d", dp[n]);
}
