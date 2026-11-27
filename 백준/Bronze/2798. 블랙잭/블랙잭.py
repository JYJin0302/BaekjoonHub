import sys
from itertools import combinations as c
input = sys.stdin.readline
a, target = map(int, input().split())
digits = list(c(list(map(int, input().split())), 3))

result = [sum(i) for i in digits if sum(i) <= target]
result.sort(key=lambda x: target - x)
print(result[0])