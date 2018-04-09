#include <stdio.h>

int main()
{
    int t, v, e;
    scanf("%d", &t);
    while(scanf("%d %d", &v, &e)!=EOF)
        printf("%d\n", 2+e-v);
}
