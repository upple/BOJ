#include<cstdio>
#include<map>
using namespace std;
int main()
{
    map<int, int> arr;
    int max=0, sum=0;

    for(int i=0; i<10; i++)
    {
        int num;
        scanf("%d", &num);
        sum+=num;
        if(arr[max]<++arr[num])
            max=num;
    }
    printf("%d %d", sum/10, max);
}
