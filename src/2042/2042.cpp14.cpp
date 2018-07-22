#include<cstdio>
#include<map>
using namespace std;

map<pair<int, int>, long long> M;
int n;
void push(int pos, int val)
{
    int begin=1, end=n;
    while(1)
    {
        int mid=(begin+end)/2;
        M[{begin, end}]+=val;
        if(begin==end)
            return;

        if(pos<=mid)
            end=mid;

        else
            begin=mid+1;
    }
}
void trade(int a, long long b)
{
    int begin=1, end=n;
    long long temp=M[{a, a}];
    while(1)
    {
        int mid=(begin+end)/2;
        M[{begin, end}]+=b-temp;
        if(begin==end)
            return;

        if(a<=mid)
            end=mid;

        else
            begin=mid+1;
    }
}
long long getSum(int begin, int end, int a, int b)
{
    int mid=(begin+end)/2;

    if(begin>=a && end<=b)
        return M[{begin, end}];

    if(a>mid)
        return getSum(mid+1, end, a, b);

    else if(b<=mid)
        return getSum(begin, mid, a, b);

    else
        return getSum(begin, mid, a, b)+getSum(mid+1, end, a, b);
}
int main()
{
    int m, k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i=1; i<=n; i++)
    {
        long long num;
        scanf("%lld", &num);
        push(i, num);
    }
    m+=k;
    while(m--)
    {
        int t, a;
        long long b;
        scanf("%d %d %lld", &t, &a, &b);
        if(t==1)
            trade(a, b);

        else
            printf("%lld\n", getSum(1, n, a, (int)b));
    }
}
