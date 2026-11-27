import sys
n = int(input())
for i in range(n):
    a = sys.stdin.readline().split('X')
    result = 0
    for b in a:
        c = b.count('O')
        result += c*(c+1)//2
    print(result)