#include <iostream>
#define MOD 1000000009
using namespace std;

int dp[100001] = { 0, 1, 2, 4, };
int solve(int x)
{
	if (x <= 0) return 0;
	if (dp[x]) return dp[x];
	return dp[x] = ((solve(x - 1) + solve(x - 2)) % MOD + solve(x - 3)) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
        int ans=0;
		for(int i=0; i<=3; i++)
        {
            int t=n-i;
            if(t%2==0) ans=(ans+solve(t/2)+(t==0))%MOD;
        }
        cout<<ans<<"\n";
	}
}