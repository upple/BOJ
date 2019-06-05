n=int(input())
a=0
b=1

if n==0:
    b=0

for i in range(1, n):
    tmp=b
    b=a+b
    a=tmp
    
print(b)
