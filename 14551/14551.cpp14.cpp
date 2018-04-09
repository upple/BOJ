#include<cstdio>
using namespace std;
int main()
{
    int n, m, ans=1;
    scanf("%d %d", &n, &m);

    while(n--)
    {
        int num;
        scanf("%d", &num);
        if(!num)
            num=1;

        ans=(ans*num)%m;
    }

    printf("%d\n", ans%m);

}
