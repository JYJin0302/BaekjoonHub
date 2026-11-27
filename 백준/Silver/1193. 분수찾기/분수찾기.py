import math
n = int(input())
place = math.ceil((-1+(1 + 8 * n)**.5)/2)
sum = place + 1
num = n - place*(place - 1)//2
den = sum - num
if place % 2 == 0:
    print(f'{num}/{den}')
else:
    print(f'{den}/{num}')