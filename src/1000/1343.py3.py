Input = list(map(str, input().split('.')))
ans=''
for s in Input:
    if len(s)%2:
        print(-1)
        exit(0)

    l=len(s)
    ans+='AAAA'*(l//4)
    l%=4
    ans+='BB'*(l//2)
    ans+='.'
print(ans[:-1])
