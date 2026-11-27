def hanoi(f, t, h):
    if h == 1:
        print(f'{f} {t}')
    else:
        k = 6 - f - t
        hanoi(f, k, h-1)
        print(f'{f} {t}')
        hanoi(k, t, h-1)

n = int(input())
print(2**n -1)
if n <= 20:
    hanoi(1, 3, n)