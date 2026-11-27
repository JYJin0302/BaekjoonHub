a = input()
result = 0
for i in range(ord('a'), ord('z') + 1):
    result += a.count(chr(i))
for i in ['dz=', 'lj', 'nj']:
    result -= a.count(i)
print(result)