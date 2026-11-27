n = int(input())

grid = [[0 for i in range(n)] for j in range(n)]

for i in range(n):
    grid[i] = list(map(int, input().split()))

path = [[0 for i in range(n)] for j in range(n)]
path[0][0] = 1

for i in range(n):
    for j in range(n):
        k = grid[i][j]
        if k == 0: continue
        if (i + k) < n:
            path[i+k][j] += path[i][j]
        if (j + k) < n:
            path[i][j+k] += path[i][j]

print(path[n-1][n-1])