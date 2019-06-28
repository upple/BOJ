n=int(input())

x='('+input()+')'

while 1:
    n-=1
    if n==0: 
        break

    x+=input()
    if x[-1]=='/': x+='/'
    x+='('+input()+')'
print(eval(x))
