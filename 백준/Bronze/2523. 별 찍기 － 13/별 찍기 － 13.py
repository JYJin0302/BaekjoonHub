n = int(input())
print('\n'.join('*'*(i+1) for i in range(n)))
print('\n'.join('*'*(i) for i in range(n - 1, 0, -1)))