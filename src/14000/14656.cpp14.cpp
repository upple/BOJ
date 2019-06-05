#include<cstdio>

using namespace std;

int main()
{
    int n, ans=0;
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++)
    {
        int num;
        scanf("%d", &num);
        if(i!=num)
            ans++;
    }
    printf("%d\n", ans);
}