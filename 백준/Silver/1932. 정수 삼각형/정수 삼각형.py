import sys
input = sys.stdin.readline

base = []
for _ in range(int(input())):
    base.append(list(map(int, input().split())))

for i in range(len(base) - 2, -1, -1):
    for j in range(len(base[i])):
        base[i][j] += max(base[i + 1][j], base[i + 1][j + 1])

print(base[0][0])