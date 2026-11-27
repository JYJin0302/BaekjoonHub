import sys
from math import ceil
for i in range(int(sys.stdin.readline())):
    a, b = map(int, sys.stdin.readline().split())
    target = b - a
    
    n = ceil(target**0.5)
    if target <= n*(n-1):
        print((n-1)*2)
    else:
        print(n*2-1)