n, m=map(int, input().split())

for a, b in [list(map(int, input().split())) for _ in range(n)]:
    if a!=b:
        print('Wrong Answer')
        exit(0)

for a, b in [list(map(int, input().split())) for _ in range(m)]:
    if a!=b:
        print('Why Wrong!!!')
        exit(0)

print('Accepted')