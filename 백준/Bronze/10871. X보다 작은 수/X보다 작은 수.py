import sys
n, x = map(int, input().split())
print(' '.join([i for i in sys.stdin.readline().split() if int(i) < x]))