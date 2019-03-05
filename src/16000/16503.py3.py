s=input().split()

a=int(eval(str(int(eval(s[0]+s[1]+s[2])))+s[3]+s[4]))
b=int(eval(s[0]+s[1]+str(int(eval(s[2]+s[3]+s[4])))))
print(min(a, b))
print(max(a, b))