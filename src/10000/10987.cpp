#include <cstdio>
int main()
{
    char ch[101];
    int count=0;
    scanf("%s", ch);
    for(int i=0; ch[i]; i++)
    {
        switch(ch[i])
        {
        case 'a': case 'e': case 'i': case 'o': case 'u':
            count++;
        }
    }
    printf("%d", count);
}
