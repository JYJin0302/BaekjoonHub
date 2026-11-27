import sys

input = sys.stdin.readline

base = []
n = int(input())
for i in range(n):
    base.append(tuple(map(int, input().split())))

result = []
for j in base:
    result.append(str(len([1 for i in base if (i[0] > j[0] and i[1] > j[1])]) + 1))

print(' '.join(result))