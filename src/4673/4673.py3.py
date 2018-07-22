v=[False for i in range(10001)]
for i in range(1, 10001):
    if v[i]==False:
        print(i)
        t=i
        for j in str(i):
            t+=int(j)
        while t<=10000:
            v[t]=1
            for j in str(t):
                t+=int(j)
