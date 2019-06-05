from decimal import *
getcontext().prec=1000
t=int(input())
while t:
    t-=1
    n=int(input())

    ret=Decimal(n)**(Decimal(1.0)/Decimal(3.0))
    print(Decimal(int(((ret+Decimal(5.0)*(Decimal(10)**Decimal(-500)))*Decimal(10000000000.0))))*(Decimal(1.0)/Decimal(10000000000.0)))
