def tri(n):
    base = [1, 1, 1, 2, 2, 3, 4, 5, 7, 9]
    if n <= 10:
        return base[n - 1]
    while len(base) < n:
        base.append(base[-1] + base[-5])
    return base[-1]

for _ in range(int(input())):
    print(tri(int(input())))