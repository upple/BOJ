#include <cstdio>

int main()
{
   int num, ans;
   scanf("%d", &ans);
   for(int i=0; i<9; i++)
   {
       scanf("%d", &num);
       ans-=num;
   }
   printf("%d\n", ans);
}
