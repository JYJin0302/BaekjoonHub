n = int(input())
base = []
for _ in range(n):
    base.append(list(map(int, input().split())))

base.sort(key= lambda x: (x[1], x[0]))

cnt = 1
min = base[0][1]
for i in range(1, n):
    if base[i][0] >= min:
        min = base[i][1]
        cnt += 1

print(cnt)

