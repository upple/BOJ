#include <cstdio>
#include <set>
using namespace std;

set<int> S;
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        int x;
        scanf("%d", &x);
        S.insert(x);
    }

    for(int i : S)
        printf("%d ", i);
}