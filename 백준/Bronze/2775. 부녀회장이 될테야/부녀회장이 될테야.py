import sys
from math import factorial as f
for i in range(int(input())):
    a = int(sys.stdin.readline().rstrip())
    b = int(sys.stdin.readline().rstrip())
    print(f(a+b)//(f(a + 1)*f(b -1)))