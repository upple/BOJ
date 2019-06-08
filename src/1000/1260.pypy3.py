import queue
n, m, v=map(int, input().split())
adj=[[] for i in range(n+1)]
visit=[False for i in range(n+1)]
def dfs(x):
    print(x, end=' ')
    visit[x]=True
    for next in sorted(adj[x]):
        if visit[next]==False:
            dfs(next)

def bfs(x):
    visit=[False for i in range(n+1)]
    Q=queue.Queue()
    Q.put(x)
    visit[x]=True
    while Q.qsize():
        cur=Q.get()
        print(cur, end=' ')

        for next in sorted(adj[cur]):
            if not visit[next]:
                visit[next]=True, Q.put(next)



while m:
    m-=1
    a, b=map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)
    
dfs(v)
print()
bfs(v)