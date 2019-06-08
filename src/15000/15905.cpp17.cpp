#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> arr[66];
int p[9];
int main()
{
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>arr[i].first>>arr[i].second;
        p[arr[i].first]++;
    }

    sort(arr, arr+n);

    for(int i=0; i<5; i++)
        p[arr[n-i-1].first]--;

    cout<<p[arr[n-5].first];
}