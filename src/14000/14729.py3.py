import sys
[print('%.3f'%i) for i in sorted([float(sys.stdin.readline()) for _ in range(int(input()))])[:7]]