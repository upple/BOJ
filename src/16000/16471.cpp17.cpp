#include <bits/stdc++.h>
using namespace std;

int a[100001], b[100001];
int n;
int solve(int x, int y)
{
    if(x>n || y>n) return 0;
    if(a[x]<b[y]) return 1+solve(x+1, y+1);
    return solve(x, y+1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i];

    for(int i=1; i<=n; i++)
        cin>>b[i];

    sort(a+1, a+n+1);
    sort(b+1, b+n+1);

    cout<<(solve(1, 1)>n/2?"YES":"NO");

}