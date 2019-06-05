#include <cstdio>

int main()
{
    int a, b, c, x, y, cnt=0;
    bool chk=false;
    scanf("%d %d %d", &a, &b, &c);

    for(int i=-100; i<=100; i++)
    {
        if(a*i*i+b*i+c==0)
        {
            cnt++;
            if(!chk)
                x=i, chk=true;

            else
                y=i;
        }
    }

    if(cnt==2)
    {
        if(x>=2 && y>=2 && (x&-x)==x && (y&-y)==y) puts("이수근");
        else puts("정수근");
    }

    else puts("둘다틀렸근");
}