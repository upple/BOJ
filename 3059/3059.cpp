#include <cstdio>
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        bool arr[91]={};
        char str[1001];
        int ans=0;
        scanf("%s", str);
        for(int i=0; str[i]; i++)
            arr[str[i]]=true;

        for(int i=65; i<=90; i++)
            ans+=(arr[i]?0:i);

        printf("%d\n", ans);
    }
}
