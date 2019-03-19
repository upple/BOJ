P, k=map(int, input().split())

chk=[False]*1000001
prime=[]
for i in range(2, k):
    if chk[i]==False:
        prime.append(i)
        t=i+i
        while t<=1000000:
            chk[t]=True
            t+=i

for p in prime:
    if p>k: break
    if P%p==0:
        print('BAD', p)
        exit(0)

print('GOOD')