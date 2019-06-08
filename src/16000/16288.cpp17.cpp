#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
int main()
{
    int n, k;
    cin>>n>>k;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        if(ans.empty() || ans.back()<-x) ans.push_back(-x);
        else
        {
            int it = lower_bound(ans.begin(), ans.end(), -x)-ans.begin();
            ans[it]=-x;
        }
    }

    cout<<(ans.size()<=k?"YES":"NO");
}