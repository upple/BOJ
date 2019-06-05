#include <bits/stdc++.h>
using namespace std;

vector<pair<int, pair<int, int> > > arr;
int input[5001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int w, n;
    cin>>w>>n;
    for(int i=0; i<n; i++)
    {
        cin>>input[i];
        for(int j=0; j<i; j++)
        {
            arr.push_back({input[i]+input[j], {i, j}});
        }
    }

    sort(arr.begin(), arr.end());

    int l=0, r=arr.size()-1;

    while(l<r)
    {
        int sum=arr[l].first+arr[r].first;
        if(sum==w)
        {
            set<int> S = {arr[l].second.first, arr[l].second.second, arr[r].second.first, arr[r].second.second};
            if(S.size()==4)
            {
                cout<<"YES";
                return 0;
            }
            else
            {
                l++;
            }
        }
        else if(sum>w)
        {
            r--;
        }
        else
        {
            l++;
        }
    }

    cout<<"NO";
}