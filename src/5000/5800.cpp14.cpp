#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);

    for(int c=1; c<=t; c++)
    {
        int n, mx=0, mn=289, lg=0;
        scanf("%d", &n);
        int *arr=new int[n];
        for(int i=0; i<n; i++)
        {
            scanf("%d", &arr[i]);
            mx=max(mx, arr[i]), mn=min(mn, arr[i]);
        }
        sort(arr, arr+n);
        for(int i=0; i<n-1; i++)
            lg=max(arr[i+1]-arr[i], lg);

        printf("Class %d\n", c);
        printf("Max %d, Min %d, Largest gap %d\n", mx, mn, lg);
        delete []arr;
    }
}
