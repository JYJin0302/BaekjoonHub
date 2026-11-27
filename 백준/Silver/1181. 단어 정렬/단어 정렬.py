import sys
input = sys.stdin.readline

base = []
for i in range(int(input())):
    base.append(input().rstrip('\n'))

base = list(set(base))
base.sort(key=lambda x: (len(x), x))

for i in base:
    print(i)