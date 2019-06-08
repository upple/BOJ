#include <cstdio>
int main()
{
    char str[1001];
    scanf("%s", str);
    for(int i=0; str[i]; i++)
        str[i]=(str[i]-'A'+23)%26+'A';

    printf("%s", str);
}
