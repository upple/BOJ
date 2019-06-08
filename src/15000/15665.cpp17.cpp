#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> ans, arr;

void solve(int c)
{
    if(c==m)
    {
        for(int i : ans)
            cout<<i<<' ';

        cout<<'\n';
        return;
    }

    int last=0;
    for(int i=0; i<n; i++)
    {
        if(i>0 && arr[last]==arr[i]) continue;
        ans.push_back(arr[i]);
        solve(c+1);
        ans.pop_back();
        last=i;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);

    cin>>n>>m;
    arr.resize(n);
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    sort(arr.begin(), arr.end());
    solve(0);
}