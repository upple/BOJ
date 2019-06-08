import os
buffer = list(map(int, os.read(0, 1000000).split()))
n=buffer[0]
arr=sorted(buffer[1:])
ans=0

k=1
for i in range(len(arr)):
    if arr[i]<k: continue
    ans+=arr[i]-k
    k+=1

print(ans)
