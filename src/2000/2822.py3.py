li = [[int(input()), i] for i in range(1, 9)]

li = sorted(li)

ans = sorted([[j, i] for i, j in li[3:]])
sum = 0
for i, j in ans:
    sum+=j

print(sum)
for i, j in ans:
    print(i, end=' ')

