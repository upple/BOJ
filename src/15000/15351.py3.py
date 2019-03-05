import sys

n=int(input())
for p in range(n):
    str=sys.stdin.readline()
    ans=0
    for ch in str:
        if ch.isalpha():
           ans+= ord(ch)-ord('A')+1
        
    if ans==100:
        print("PERFECT LIFE")
        
    else:
        print(ans)