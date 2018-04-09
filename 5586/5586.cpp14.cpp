#include <cstdio>

int main()
{
    char str[10001];
    int count_j=0, count_i=0;
    scanf("%s", str);

    for(int i=0; str[i+2]; i++)
    {
        if(str[i+1]=='O' && str[i+2]=='I')
        {
            if(str[i]=='J')
                count_j++;

            else if(str[i]=='I')
                count_i++;
        }
    }

    printf("%d\n%d", count_j, count_i);
}
