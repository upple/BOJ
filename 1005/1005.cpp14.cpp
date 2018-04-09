#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int main()
{
   int t;
   scanf("%d", &t);
   while (t--)
   {
      int n, k, dest;
      scanf("%d %d", &n, &k);
      vector<vector<pair<int, int> > > adj(n+1);
      vector<vector<int> > p(n+1);
      vector<int> cost(n+1), dist(n+1);
      priority_queue<pair<int, int> > pq;
      for (int i = 1; i <= n; i++)
         scanf("%d", &cost[i]), dist[i]=0;
      for (int i = 1; i <= k; i++)
      {
         int s, e;
         scanf("%d %d", &s, &e);
         adj[s].push_back({ cost[e], e });
         p[e].push_back(s);
      }

      for(int i=1; i<=n; i++)
        if(p[i].empty())
            pq.push({cost[i], i}), dist[i]=cost[i];

      while (!pq.empty())
      {
         int c = pq.top().first;
         int d = pq.top().second;
         pq.pop();
         for (auto i : adj[d])
         {
            if (dist[i.second] < dist[d] + i.first)
               dist[i.second] = dist[d] + i.first, pq.push({ dist[i.second], i.second });
         }
      }

      scanf("%d", &dest);
      printf("%d\n", dist[dest]);
   }
}
