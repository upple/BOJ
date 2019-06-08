#include <iostream>
using namespace std;

long long arr[1001][1001];
int main()
{
    int n, m;
    cin>>n>>m;
    arr[0][0]=1;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            arr[i][j]=(arr[i-1][j]+arr[i-1][j-1]+arr[i][j-1])%(1000000007);
        }
    }

    cout<<arr[n][m];
}