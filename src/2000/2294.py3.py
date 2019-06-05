import queue
n, k=map(int, input().split())
v=[False for i in range(k+1)]
m=[int(input()) for i in range(n)]
Q = queue.Queue()
v[k]=1
cnt=0
Q.put(k)
while Q.qsize():
    size=Q.qsize()
    while size:
        size-=1
        cur=Q.get()
        if cur==0:
            print(cnt)
            exit(0)

        for i in m:
            if cur-i>=0 and not v[cur-i]:
                v[cur-i]=True
                Q.put(cur-i)

    cnt+=1

print(-1)
