from math import sqrt as sq

a, b, c = map(int, input().split())
cos = (a*a + b*b - c*c) / (2*a*b)
sin = sq(1 - cos*cos)

S = a*b*sin/2
R = c/(2*sin)
r = 2*S/(a+b+c)
if a == b and a == c: d = 0
else: d = sq(R*(R-2*r))
k = sq(R*R - a*a/4) + sq(R*R - b*b/4) + sq(R*R - c*c/4)

print(S, R, r, d, k, sep='\n')