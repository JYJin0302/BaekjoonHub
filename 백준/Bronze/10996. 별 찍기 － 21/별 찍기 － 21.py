n = int(input())
if n == 1:
    print('*')
elif n % 2 == 0:
    print('\n'.join(['* '*(n // 2), ' *'*(n // 2)] * n))
else:
    print('\n'.join(['* '*(n // 2) + '*', ' *'*(n // 2)] * n))