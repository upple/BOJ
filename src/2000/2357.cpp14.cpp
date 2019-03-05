#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

vector<pair<int, int> >tree(400001, {1000000001, 0});

pair<int, int> getAns(int begin, int end, int s, int e, int x)
{
    int mid=(begin+end)/2;
    if(s<=begin && e>=end)
        return tree[x];

    if(s>mid)
        return getAns(mid+1, end, s, e, x*2+1);

    else if(e<=mid)
        return getAns(begin, mid, s, e, x*2);

    else
    {
        pair<int, int>a=getAns(mid+1, end, s, e, x*2+1);
        pair<int, int>b=getAns(begin, mid, s, e, x*2);
        return {min(a.first, b.first), max(a.second, b.second)};
    }
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int d=0;
    while(pow(2, ++d)<n);
    d=(int)pow(2, d);
    for(int i=d; i<d+n; i++)
    {
        int num;
        scanf("%d", &num);
        int temp=i;
        while(temp)
        {
            tree[temp].first=min(tree[temp].first, num);
            tree[temp].second=max(tree[temp].second, num);
            temp/=2;
        }
    }
    while(m--)
    {
        int s, e;
        scanf("%d %d", &s, &e);
        pair<int, int> ans=getAns(1, d, s, e, 1);
        printf("%d %d\n", ans.first, ans.second);
    }
}
