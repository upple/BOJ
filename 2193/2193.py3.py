n=int(input())
if n<2:
    print(1)
    exit(0)

a, b=1, 0

for i in range(2, n):
    na=a+b
    nb=a
    a, b=na, nb

print(a+b)