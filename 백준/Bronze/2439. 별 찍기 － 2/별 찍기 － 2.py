n = int(input())
print('\n'.join([format('*'*(i+1), f'>{n}') for i in range(n)]))