#include <bits/stdc++.h>
using namespace std;

int arr[501];
vector<int> ans;
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int a, b;
        cin>>a>>b;
        arr[a]=b;
    }

    for(int i=1; i<=500; i++)
    {
        if(arr[i]==0) continue;
        if(ans.empty() || ans.back()<arr[i]) ans.push_back(arr[i]);
        else *(lower_bound(ans.begin(), ans.end(), arr[i]))=arr[i];
    }

    cout<<n-ans.size();
}