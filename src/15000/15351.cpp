#include <cstdio>
#include <cctype>

int main()
{
    int n;
    char str[31];
    scanf("%d", &n);
    
    gets(str);
    while(n--)
    {
        gets(str);
        int ans=0;
        for(int i=0; str[i]; i++)
        {
            if(isalpha(str[i]))
                ans+=str[i]-'A'+1;
            
        }
    
        if(ans==100)
            printf("PERFECT LIFE\n");
    
        else
            printf("%d\n", ans);
    }
}