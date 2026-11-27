import sys
while 1:
    a, b, c = sorted(list(map(int, sys.stdin.readline().split())))
    if a == b == c == 0:
        break
    
    if a**2 + b**2 - c**2 == 0:
        print('right')
    else:
        print('wrong')