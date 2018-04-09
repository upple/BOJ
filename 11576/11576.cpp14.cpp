#include <cstdio>
#include <cmath>
int main()
{
    int a, b, n;
    int ans=0, num;
    scanf("%d %d %d", &a, &b, &n);

    for(int i=n-1; i>=0; i--)
    {
        scanf("%d", &num);
        ans+=num*(int)pow(a, i);
    }
    int temp=-1;
    while(ans>(int)pow(b, (++temp)));

    while(temp)
    {
        printf("%d ", ans/(int)pow(b, --temp));
        ans%=(int)pow(b, temp);
    }

}
