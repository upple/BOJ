#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    vector<int> adj[7];
    int n, p, count=0;
    scanf("%d %d", &n, &p);
    for(int i=0; i<n; i++)
    {
        int num, pos;
        scanf("%d %d", &num, &pos);
        while(1)
        {
            if(adj[num].empty() || adj[num].back()<pos)
            {
                count++, adj[num].push_back(pos);
                break;
            }

            if(adj[num].back()==pos)
                break;

            adj[num].pop_back();
            count++;
        }
    }
    printf("%d", count);
}
