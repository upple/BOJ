import sys as S
[S.stdout.write('%.3f\n'%i) for i in sorted([float(S.stdin.readline()) for _ in range(int(input()))])[:7]]