n, m = map(int, input().split())
arr1 = ['' for i in range(n+1)]
arr2={}

for i in range(1, n+1):
    poke=input()
    arr1[i]=poke
    arr2[poke]=i

for i in range(m):
    cmd=input()
    if cmd.isdigit():
        print(arr1[int(cmd)])

    else:
        print(arr2[cmd])