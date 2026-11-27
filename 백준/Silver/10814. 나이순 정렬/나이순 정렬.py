import sys

input = sys.stdin.readline

base = []
for i in range(int(input())):
    base.append(input().rstrip('\n'))

base.sort(key=lambda x: int(x.split()[0]))

for i in base:
    print(''.join(i))