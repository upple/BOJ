while 1:
    a = list(map(int, input().split()))
    if a[0]==-1:
        break

    ans = 0
    for k in a[:-1]:
        if k*2 in a:
            ans+=1

    print(ans)
    