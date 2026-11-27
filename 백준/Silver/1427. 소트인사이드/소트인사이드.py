a = input()
b = list(a)
b.sort()
for i in range(len(b)-1, -1, -1):
    print(b[i], end='')