#include <cstdio>
#include <map>
using namespace std;
int main()
{
    int n;
    pair<int, int> arr[200001]={};
    map<int, map<int, int> > M;

    scanf("%d", &n);
    auto &MO=M[0];
    for(register int i=1; i<=n; i++)
    {
        scanf("%d %d", &arr[i].first, &arr[i].second);

        MO[arr[i].second]+=arr[i].second;
        M[arr[i].first][arr[i].second]-=arr[i].second;
    }
    int temp, temp2;
    auto end=M.end();
    for(register auto i=M.begin(); i!=end; i++)
    {
        temp=0;
        register auto iend=i->second.end();
        for(register auto j=i->second.begin(); j!=iend; j++)
            temp2=temp+j->second, j->second=temp, temp=temp2;
    }
    int sum;
    for(register int i=1; i<=n; i++)
        printf("%d\n", MO[arr[i].second]+M[arr[i].first][arr[i].second]);
}
