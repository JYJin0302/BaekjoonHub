def fivo(n):
    if n == 1:
        return 1
    if n == 0:
        return 0
    return fivo(n-1)+fivo(n-2)

print(fivo(int(input())))