#include <cstdio>
int main()
{
    int n, no2=0, no5=0;
    scanf("%d", &n);
    for(int i=2; i<=n; i++)
    {
        int temp=i;
        while(!(temp%5))
            no5++, temp/=5;

        while(!(temp%2))
            no2++, temp/=2;
    }
    printf("%d", no2>no5?no5:no2);
}
