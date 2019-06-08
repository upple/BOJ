import queue
n=int(input())

Q=queue.Queue()
for i in range(1, n+1):
    Q.put(i)
    
while Q.qsize()!=1:
    Q.get()
    Q.put(Q.get())

print(Q.get())