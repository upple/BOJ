h, w, n=map(int, input().split())

n-=1
if n%2==1:
    ans=(n-1)*w/2
    
else:
    n+=1
    ans=0
    i=1
    while i<n:
        ans+=i
        i+=2
    ans=ans*w/n*2
    
print(ans)