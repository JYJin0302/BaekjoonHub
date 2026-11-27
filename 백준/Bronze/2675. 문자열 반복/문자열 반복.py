import sys
for i in range(int(input())):
    base = sys.stdin.readline()
    a, b = base.rstrip().split()
    print(''.join(list(map(lambda x: x*int(a), b))))