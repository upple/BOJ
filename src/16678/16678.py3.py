n=int(input())
arr=sorted([int(input()) for i in range(n)])
ans=0

k=1
for i in range(len(arr)):
    if arr[i]<k: continue
    ans+=arr[i]-k
    k+=1

print(ans)
