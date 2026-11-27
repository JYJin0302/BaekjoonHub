import sys
input = sys.stdin.readline

base = []
for i in range(int(input())):
    base.append(list(input().split()))

base.sort(key=lambda x: (int(x[1]), int(x[0])))

for i in base:
    print(' '.join(i))