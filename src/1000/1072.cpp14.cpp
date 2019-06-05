#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    long long x, y, z;
    while(scanf("%lld %lld", &x, &y)!=EOF)
    {
        z=(y*100)/x;
        if(z>=99)
        {
            printf("-1\n");
            continue;
        }

        long long left=0, right=1000000000, mid;
        while(left<right)
        {
            mid=(left+right)/2;
            long long pos=(y+mid)*100/(x+mid);
            if(pos>z)
                right=mid;

            else if(pos==z)
                left=mid+1;
        }

        printf("%lld\n", left);
    }
}
