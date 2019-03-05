#include<cstdio>
using namespace std;
int main()
{
    int ans=0, x, y;
    for(int i=1; i<=9; i++)
        for(int j=1; j<=9; j++)
        {
            int num;
            scanf("%d", &num);
            if(num>ans)
                ans=num, x=i, y=j;
        }

    printf("%d\n%d %d", ans, x, y);
}
