n = int(input())
base = [0, 1]
while len(base) <= n:
    base.append(base[-1]+base[-2])
print(base[-1])