import sys
n = int(sys.stdin.readline())
for i in range(n):
    a, b = sys.stdin.readline().split()
    print(f'Case #{i+1}: {int(a) + int(b)}')