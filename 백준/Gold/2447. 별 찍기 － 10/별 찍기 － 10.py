def star(n):
    if n == 3:
        return ['***', '* *', '***']
    
    a = star(n//3)
    b = a*3
    for i in range(n):
        if i < n//3 or i >= 2*n//3:
            b[i] *= 3
        else:
            c = b[i]
            b[i] = c + ' '*len(c) + c
    return b

for i in star(int(input())):
    print(i)