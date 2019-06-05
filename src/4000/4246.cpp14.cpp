#include <cstdio>
using namespace std;

int main()
{
    int n;
    while(scanf("%d", &n))
    {
        if(!n)
            return 0;

        char str[201], arr[20][101]={};
        scanf("%s", str);
        for(int i=0; str[i]; i++)
        {
            char * ptr;
            if(i/n%2)
                ptr=&arr[n-1-(i%n)][i/n];
            else
                ptr=&arr[i%n][i/n];

            *ptr=str[i];

        }

        for(int i=0; i<n; i++)
            printf("%s", arr[i]);

        printf("\n");
    }
}
