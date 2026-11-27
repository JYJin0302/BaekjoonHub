n = int(input())
base = [0, 1, 2]
for i in range(n - 2):
    new = base[-1] + base[-2]
    base.append(new%15746)
print(base[n])