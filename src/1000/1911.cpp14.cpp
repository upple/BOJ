#include<cstdio>
#include<algorithm>
using namespace std;

pair<int, int> arr[10000];
int main()
{
    int n, u;
    scanf("%d %d", &n, &u);

    for(int i=0; i<n; i++)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        arr[i]={l, r};
    }

    sort(arr, arr+n);
    int cur=-1, ans=0;
    for(int i=0; i<n; i++)
    {
        int l = max(arr[i].first, cur), r=arr[i].second;
        if(l>=r) continue;
        int c=(r-l)/u+(((r-l)%u)!=0);
        ans+=c;
        cur=l+c*u;
    }

    printf("%d", ans);
}