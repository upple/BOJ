#include <cstdio>
#include <string>

int main()
{
    int n;
    scanf("%d", &n);

    for(int num=1; num<100000 && n-num; num++)
    {
        bool check[10]={}, isAns=1;
        std::string str=std::to_string(num)+std::to_string(n-num);
        for(auto &ch : str)
        {
            if(check[ch-'0'])
            {
                isAns=0;
                break;
            }

            check[ch-'0']=1;
        }

        if(isAns)
        {
            printf("%d + %d", n-num, num);
            return 0;
        }
    }

    printf("-1");
}
