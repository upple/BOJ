#include<cstdio>
#include<vector>
using namespace std;
int main()
{
    bool adj[1001][1001];
    int n, m, k;
    bool check[4]={};
    scanf("%d %d %d", &n, &m, &k);
    while(k--)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        if(x%2)
        {
            if(y%2)
                check[0]=true;
            else
                check[1]=true;
        }
        else
        {
            if(y%2)
                check[2]=true;

            else
                check[3]=true;
        }

    }
    printf("%s", (check[0] && check[1] && check[2] && check[3]?"YES":"NO"));
}
