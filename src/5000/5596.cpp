#include <cstdio>
#include <algorithm>

int main(){
    int a, b, c, d, sum;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    sum=a+b+c+d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    printf("%d", std::max(sum, a+b+c+d));
}