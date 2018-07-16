import queue

n, m=map(int, input().split())
d=[[1, 0], [0, 1], [-1, 0], [0, -1]]
map=[]
for i in range(n):
    map.append(list(input()))

Q=queue.Queue()
Q.put([0, 0])
map[0][0]='0'
cnt=1
while Q.qsize():
    size=Q.qsize()
    while size:
        size-=1
        [x, y]=Q.get()

        if [x, y] == [n-1, m-1]:
            print(cnt)
            exit(0)

        for [dx, dy] in d:
            nx=x+dx
            ny=y+dy
            if nx>=0 and nx<n and ny>=0 and ny<m and map[nx][ny]=='1':
                map[nx][ny]='0'
                Q.put([nx, ny])

    cnt+=1