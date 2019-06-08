#include <cstdio>

int main()
{
    int n, m, j, l, ans=0;
    scanf("%d %d %d", &n, &m, &j);
    l=m;
    m--;
    for(int i=0; i<j; i++)
    {
        int a;
        scanf("%d", &a);
        if(a<l-m)
            ans+=l-m-a, l=a+m;

        else if(a>l)
            ans+=a-l, l=a;
    }
    printf("%d", ans);
}