#include<cstdio>
#include<vector>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, count=0;
        scanf("%d", &n);
        int *arr=new int[n+1];
        for(int i=1; i<=n; i++)
            scanf("%d", &arr[i]);

        for(int i=1; i<=n; i++)
        {
            if(arr[i])
            {
                count++;
                int pos=arr[i];
                while(pos)
                {
                    int temp=arr[pos];
                    arr[pos]=0;
                    pos=temp;
                }
            }
        }

        printf("%d\n", count);
        delete []arr;
    }
}
