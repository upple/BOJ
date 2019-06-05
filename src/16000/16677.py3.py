m=input()
n=int(input())
ans=''
sudden=0

def valid(a, b):
    if len(a)<=len(b): return False
    j=0
    for i in range(len(a)):
        if j==len(b): return True
        if a[i]==b[j]: j+=1

    return j==len(b)


for i in range(n):
    w, g = input().split()
    g=int(g)

    if valid(w, m):
        tmp=g/(len(w)-len(m))
        if tmp>sudden:
            ans=w
            sudden=tmp

print('No Jam' if sudden==0 else ans)
 